#pragma once

#include "../../sdk/FakeRW.h"
#include "../../ui/CVisual.h"
#include "../../core/CGame.h"
#include <string>
#include <vector>

class CSkinSelector {
public:
    static void Initialise();
    static void Shutdown();
    static void SkinSelectorMenu();
    static int SkinSelectorMenuHandler();
    static bool LoadModelFile(const char* skinName);
    static void RenderPlayerModel();

    static int g_MenuSkinOption;
    static int g_MaxMenuSkinOptions;
    static std::vector<std::string> g_SkinList;
    static std::string g_SkinPath;

private:
    static void LoadSkinList();
    static void UnloadCurrentModel();
    static bool LoadDFFWithTextures(const char* skinName);
};