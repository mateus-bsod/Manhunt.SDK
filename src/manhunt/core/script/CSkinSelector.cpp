#include "CSkinSelector.h"
#include "../../ui/CVisual.h"
#include "../../sdk/FakeRW.h"
#include <cstdio>
#include <algorithm>
#include <windows.h>
#include <filesystem>

int CSkinSelector::g_MenuSkinOption = 0;
int CSkinSelector::g_MaxMenuSkinOptions = 0;
std::vector<std::string> CSkinSelector::g_SkinList;
std::string CSkinSelector::g_SkinPath = "Manhunt.SDK/skins/";

static RpClump* gpPlayerClump = NULL;
static RwTexDictionary* gpCurrentTXD = NULL;
static char g_CurrentPreview[256] = "";
static bool g_ModelLoaded = false;
static float g_RotationAngle = 0.0f;
static float g_Zoom = 5.0f;
static float g_HeightOffset = -1.0f;
static float g_RotationSpeed = 1.0f;
static RpLight* ms_pLight = NULL;

#define g_LightHandle (*(RpLight**)0x7137B4)
#define g_WorldRW (*(RpWorld**)0x715B8C)

void Log(const char* msg) {
    FILE* log = fopen("Manhunt.SDK/debug.log", "a");
    if (log) { fprintf(log, "%s\n", msg); fclose(log); }
}

void EnableFullBright() {
    if (!g_LightHandle) return;
    float color[3] = { 1.0f, 1.0f, 1.0f };
    RpLightSetColor(g_LightHandle, (RwRGBAReal*)color);
    *((BYTE*)g_LightHandle + 2) |= 3;
}

void LoadSkinFiles() {
    char searchPath[MAX_PATH];
    sprintf(searchPath, "%s*.dff", CSkinSelector::g_SkinPath.c_str());

    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(searchPath, &findData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                std::string fn = findData.cFileName;
                size_t dot = fn.find_last_of(".");
                if (dot != std::string::npos)
                    CSkinSelector::g_SkinList.push_back(fn.substr(0, dot));
            }
        } while (FindNextFileA(hFind, &findData));
        FindClose(hFind);
        std::sort(CSkinSelector::g_SkinList.begin(), CSkinSelector::g_SkinList.end());
        CSkinSelector::g_MaxMenuSkinOptions = CSkinSelector::g_SkinList.size();
    }
}

RpAtomic* FixModelCallback(RpAtomic* atomic, void* data) {
    if (!atomic) return atomic;

    RpGeometry* geo = RpAtomicGetGeometry(atomic);
    if (!geo) return atomic;

    RpAtomicSetFlags(atomic, RpAtomicGetFlags(atomic) & ~0x20);
    RpGeometrySetFlags(geo, RpGeometryGetFlags(geo) & ~0x08);

    RwTexDictionary* txd = (RwTexDictionary*)data;
    int numMats = RpGeometryGetNumMaterials(geo);

    for (int i = 0; i < numMats; i++) {
        RpMaterial* mat = RpGeometryGetMaterial(geo, i);
        if (!mat) continue;

        RwRGBA white = { 255, 255, 255, 255 };
        RpMaterialSetColor(mat, &white);

        if (txd) {
            RwTexture* tex = RwTexDictionaryFindNamedTexture(txd, "skin");
            if (!tex) tex = RwTexDictionaryFindNamedTexture(txd, "texture");
            if (!tex) tex = RwTexDictionaryFindNamedTexture(txd, "diffuse");
            if (tex) RpMaterialSetTexture(mat, tex);
        }
    }

    return atomic;
}

void CSkinSelector::Initialise() {
    g_SkinList.clear();
    g_MenuSkinOption = 0;
    g_MaxMenuSkinOptions = 0;
    g_CurrentPreview[0] = '\0';
    g_ModelLoaded = false;
    gpPlayerClump = NULL;
    gpCurrentTXD = NULL;
    g_RotationAngle = 0.0f;
    g_Zoom = 5.0f;
    g_HeightOffset = -1.0f;
    g_RotationSpeed = 1.0f;
    ms_pLight = NULL;

    CreateDirectoryA("Manhunt.SDK", NULL);
    CreateDirectoryA("Manhunt.SDK/skins", NULL);
    LoadSkinFiles();
    EnableFullBright();
}

void CSkinSelector::Shutdown() {
    if (gpPlayerClump) {
        if (g_WorldRW) RpWorldRemoveClump(g_WorldRW, gpPlayerClump);
        FakeRW::FRpClumpDestroy(gpPlayerClump);
        gpPlayerClump = NULL;
    }
    if (gpCurrentTXD) { FakeRW::FRwTexDictionaryDestroy(gpCurrentTXD); gpCurrentTXD = NULL; }
    if (ms_pLight) { FakeRW::FRpLightDestroy(ms_pLight); ms_pLight = NULL; }
    g_SkinList.clear();
}

void CSkinSelector::UnloadCurrentModel() {
    if (gpPlayerClump) {
        if (g_WorldRW) RpWorldRemoveClump(g_WorldRW, gpPlayerClump);
        FakeRW::FRpClumpDestroy(gpPlayerClump);
        gpPlayerClump = NULL;
    }
    if (gpCurrentTXD) { FakeRW::FRwTexDictionaryDestroy(gpCurrentTXD); gpCurrentTXD = NULL; }
    g_ModelLoaded = false;
    g_CurrentPreview[0] = '\0';
}

bool CSkinSelector::LoadModelFile(const char* skinName) {
    if (!skinName || !*skinName) return false;

    UnloadCurrentModel();

    char dffPath[MAX_PATH], txdPath[MAX_PATH];
    sprintf(dffPath, "%s%s.dff", g_SkinPath.c_str(), skinName);
    sprintf(txdPath, "%s%s.txd", g_SkinPath.c_str(), skinName);

    gpCurrentTXD = FakeRW::LoadTXD(txdPath);
    if (gpCurrentTXD) {
        FakeRW::FRwTexDictionarySetCurrent(gpCurrentTXD);
        Log("TXD loaded");
    }
    else {
        Log("TXD failed");
        return false;
    }

    RwStream* stream = FakeRW::FRwStreamOpen(rwSTREAMFILENAME, rwSTREAMREAD, dffPath);
    if (!stream) { Log("Stream failed"); return false; }

    if (FakeRW::FRwStreamFindChunk(stream, rwID_CLUMP, NULL, NULL)) {
        gpPlayerClump = FakeRW::FRpClumpStreamRead(stream);
    }
    FakeRW::FRwStreamClose(stream, NULL);

    if (!gpPlayerClump) { Log("DFF failed"); return false; }

    FakeRW::FRpClumpForAllAtomics(gpPlayerClump, FixModelCallback, gpCurrentTXD);

    if (g_WorldRW) {
        RpWorldAddClump(g_WorldRW, gpPlayerClump);
    }

    g_ModelLoaded = true;
    strcpy(g_CurrentPreview, skinName);
    g_RotationAngle = 0.0f;
    Log("Model loaded");
    return true;
}

void CSkinSelector::RenderPlayerModel() {
    if (!gpPlayerClump || !g_ModelLoaded) return;

    RwCamera* camera = FakeRW::GetCurrentCamera();
    if (!camera) return;

    // Controles de Zoom (Q e E)
    if (GetAsyncKeyState('Q') & 1) {
        g_Zoom -= 0.2f;
        if (g_Zoom < 1.0f) g_Zoom = 1.0f;
    }
    if (GetAsyncKeyState('E') & 1) {
        g_Zoom += 0.2f;
        if (g_Zoom > 20.0f) g_Zoom = 20.0f;
    }

    // Controle de Altura (R e F)
    if (GetAsyncKeyState('R') & 1) {
        g_HeightOffset += 0.2f;
    }
    if (GetAsyncKeyState('F') & 1) {
        g_HeightOffset -= 0.2f;
    }

    // Velocidade de Rotação (Z e X)
    if (GetAsyncKeyState('Z') & 1) {
        g_RotationSpeed -= 0.1f;
        if (g_RotationSpeed < 0.1f) g_RotationSpeed = 0.1f;
    }
    if (GetAsyncKeyState('X') & 1) {
        g_RotationSpeed += 0.1f;
        if (g_RotationSpeed > 5.0f) g_RotationSpeed = 5.0f;
    }

    // Reset view (R)
    if (GetAsyncKeyState('C') & 1) {
        g_Zoom = 5.0f;
        g_HeightOffset = -1.0f;
        g_RotationSpeed = 1.0f;
        g_RotationAngle = 0.0f;
    }

    RwFrame* frame = RpClumpGetFrame(gpPlayerClump);
    if (frame) {
        RwMatrix identity;
        RwMatrixSetIdentity(&identity);
        FakeRW::FRwFrameTransform(frame, &identity, rwCOMBINEREPLACE);

        RwMatrix* camMatrix = RwFrameGetMatrix(RwCameraGetFrame(camera));
        FakeRW::FRwFrameTransform(frame, camMatrix, rwCOMBINEPRECONCAT);

        RwV3d pos = { 0.0f, g_HeightOffset, g_Zoom };
        FakeRW::FRwFrameTranslate(frame, &pos, rwCOMBINEPRECONCAT);

        RwV3d axis = { 0.0f, 1.0f, 0.0f };
        g_RotationAngle += g_RotationSpeed;
        if (g_RotationAngle > 360.0f) g_RotationAngle -= 360.0f;
        FakeRW::FRwFrameRotate(frame, &axis, g_RotationAngle, rwCOMBINEPRECONCAT);

        FakeRW::FRwFrameUpdateObjects(frame);
    }

    CGame::Set2DRenderMode(0);
    FakeRW::FRpClumpRender(gpPlayerClump);
    CGame::Set2DRenderMode(1);
}

void CSkinSelector::SkinSelectorMenu() {
    if (g_MaxMenuSkinOptions == 0) {
        CVisual::DrawTextString("NO SKINS", 0.35f, 0.50f, 1.0f, 1.0f, 0, 0, 0);
        CVisual::DrawMenuInfo(L"No skins", L"SKINS", CText::GetKey("IBACK"), L"");
        return;
    }

    RenderPlayerModel();

    CVisual::DrawTextString("SKINS", 0.35f, 0.05f, 3.0f, 3.0f, 0, 0, 0);

    CVisual::DrawTextString("~white~CONTROLS:", 0.10f, 0.70f-0.10f, 0.7f, 0.7f, 0, 0, 0);
    CVisual::DrawTextString("~yellow~Q~white~ - Zoom In", 0.10f, 0.73f - 0.10f, 0.6f, 0.6f, 0, 0, 0);
    CVisual::DrawTextString("~yellow~E~white~ - Zoom Out", 0.10f, 0.76f - 0.10f, 0.6f, 0.6f, 0, 0, 0);
    CVisual::DrawTextString("~yellow~R~white~ - Raise", 0.10f, 0.79f - 0.10f, 0.6f, 0.6f, 0, 0, 0);
    CVisual::DrawTextString("~yellow~F~white~ - Lower", 0.10f, 0.82f - 0.10f, 0.6f, 0.6f, 0, 0, 0);
    CVisual::DrawTextString("~yellow~Z~white~ - Slower", 0.10f, 0.85f - 0.10f, 0.6f, 0.6f, 0, 0, 0);
    CVisual::DrawTextString("~yellow~X~white~ - Faster", 0.10f, 0.88f - 0.10f, 0.6f, 0.6f, 0, 0, 0);
    CVisual::DrawTextString("~yellow~C~white~ - Reset View", 0.10f, 0.91f - 0.10f, 0.6f, 0.6f, 0, 0, 0);

    int maxDisplay = min(12, g_MaxMenuSkinOptions);
    int startIdx = max(0, min(g_MenuSkinOption - 6, g_MaxMenuSkinOptions - maxDisplay));

    for (int i = 0; i < maxDisplay; i++) {
        int idx = startIdx + i;
        float y = 0.15f + (i * 0.045f);
        const char* prefix = (idx == g_MenuSkinOption) ? "> " : "  ";
        CVisual::DrawTextString((std::string(prefix) + g_SkinList[idx]).c_str(), 0.70f, y, 0.8f, 0.8f, 0, 0, 0);
    }

    char info[64];
    sprintf(info, "%d skins", g_MaxMenuSkinOptions);
    CVisual::DrawTextString(info, 0.70f, 0.90f, 1.6f, 1.6f, 0, 0, 0);

    if (g_ModelLoaded) {
        CVisual::DrawTextString(g_CurrentPreview, 0.05f, 0.05f, 1.8f, 1.8f, 0, 0, 0);
    }
    else {
        CVisual::DrawTextString("SELECT A SKIN", 0.05f, 0.50f, 2.0f, 2.0f, 0, 0, 0);
    }

    CVisual::DrawMenuInfo(L"Select", L"SKINS", CText::GetKey("IBACK"), L"");
}

int CSkinSelector::SkinSelectorMenuHandler() {
    if (g_MaxMenuSkinOptions == 0) {
        if (CInput::IsExitKeyPressed() || CInput::IsKeyMenuInfoPressed()) {
            CPlayer::SetMenu(MENU_CONFIG);
        }
        return 1;
    }

    if (CInput::IsUpKeyPressed()) {
        g_MenuSkinOption--;
        if (g_MenuSkinOption < 0) g_MenuSkinOption = g_MaxMenuSkinOptions - 1;
        LoadModelFile(g_SkinList[g_MenuSkinOption].c_str());
    }

    if (CInput::IsDownKeyPressed()) {
        g_MenuSkinOption++;
        if (g_MenuSkinOption >= g_MaxMenuSkinOptions) g_MenuSkinOption = 0;
        LoadModelFile(g_SkinList[g_MenuSkinOption].c_str());
    }

    if (CInput::GetSelectedOptionFromMouse()) {
        int opt = CMainMenu::getSelectionOption();
        if (opt >= 0 && opt < g_MaxMenuSkinOptions) {
            g_MenuSkinOption = opt;
            LoadModelFile(g_SkinList[g_MenuSkinOption].c_str());
        }
    }

    if (CInput::IsExitKeyPressed() || CInput::IsKeyMenuInfoPressed()) {
        UnloadCurrentModel();
        CPlayer::SetMenu(MENU_CONFIG);
        return 1;
    }

    return 1;
}