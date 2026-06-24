#pragma once

#include "../../../framework.h"
#include "../../game.sdk.h"

#include <rwcore.h>
#include <rpworld.h>
#include <rpskin.h>
#include <rphanim.h>


class FakeRW {
public:
    static RwCamera* GetCurrentCamera();
    static RpWorld* GetCurrentWorld();

    static void SetAmbientColours();

    static RwCamera* FRwCameraCreate();

    static void FRpGeometryLock(RpGeometry* geometry, RwInt32 lockMode);
    static void FRpGeometryUnlock(RpGeometry* geometry);

    static RwBool FRpWorldDestroy(RpWorld* world);
    static RpWorld* FRpWorldCreate(RwBBox* boundingBox);
    static RpMaterial* FRpMaterialSetTexture(RpMaterial* material, RwTexture* texture);
    static RwReal FRwV3dLength(const RwV3d* in);
    static RwV3d* FRwV3dTransformPoints(RwV3d* pointsOut, const RwV3d* pointsIn, RwInt32 numPoints, const RwMatrix* matrix);
    static RwMatrix* FRwMatrixInvert(RwMatrix* matrixOut, const RwMatrix* matrixIn);
    static void F_rpAtomicResyncInterpolatedSphere(RpAtomic* atomic);
    static void FCameraSize(RwCamera* camera, RwRect* rect, RwReal viewWindow, RwReal aspectRatio);
    static RpAtomic* FRpAtomicSetGeometry(RpAtomic* atomic, RpGeometry* geometry, RwUInt32 flags);

    static RpWorld* FRpWorldAddClump(RpWorld* world, RpClump* clump);
    static RpWorld* FRpWorldRemoveClump(RpWorld* world, RpClump* clump);

    static RwStream* FRwStreamOpen(RwStreamType type, RwStreamAccessType accessType, const void* pData);
    static RwBool FRwStreamFindChunk(RwStream* stream, RwUInt32 type, RwUInt32* lengthOut, RwUInt32* versionOut);
    static RwBool FRwStreamClose(RwStream* stream, void* pData);

    static RwFrame* FRwFrameTransform(RwFrame* frame, const RwMatrix* m, RwOpCombineType combine);
    static RwFrame* FRwFrameTranslate(RwFrame* frame, const RwV3d* v, RwOpCombineType combine);
    static RwFrame* FRwFrameUpdateObjects(RwFrame* frame);
    static RwFrame* FRwFrameRotate(RwFrame* frame, const RwV3d* axis, RwReal angle, RwOpCombineType combine);

    static RwCamera* FRwCameraBeginUpdate(RwCamera* camera);
    static RwCamera* FRwCameraEndUpdate(RwCamera* camera);

    // TXD functions - CORRIGIDO (todos com prefixo FRw)
    static RwTexDictionary* FRwTexDictionaryStreamRead(RwStream* stream);
    static void FRwTexDictionarySetCurrent(RwTexDictionary* dict);
    static RwTexDictionary* FRwTexDictionaryGetCurrent();
    static void FRwTexDictionaryDestroy(RwTexDictionary* dict);
    static void FRwTexDictionaryAddTexture(RwTexDictionary* dict, RwTexture* texture);
    static RwTexDictionary* FRwTexDictionaryCreate();
    static RwTexDictionary* FRwTexDictionaryForAllTextures(const RwTexDictionary* dict, RwTextureCallBack fpCallBack, void* pData);

    // Load TXD
    static RwTexDictionary* LoadTXD(const char* filePath);

    static RpLight* FRpLightCreate(RwInt32 type);
    static RpLight* FRpLightSetColor(RpLight* light, const RwRGBAReal* color);
    static RpLight* FRpLightSetRadius(RpLight* light, RwReal radius);
    static RpLight* FRpLightSetConeAngle(RpLight* light, RwReal angle);
    static RwReal FRpLightGetConeAngle(RpLight* light);
    static RwBool FRpLightDestroy(RpLight* light);
    static RpWorld* FRpWorldAddLight(RpWorld* world, RpLight* light);
    static RpWorld* FRpWorldRemoveLight(RpWorld* world, RpLight* light);
    static RpLight* FRpLightSetDirection(RpLight* light, const RwV3d* direction);

    static RwCamera* FRwCameraSetViewWindow(RwCamera* camera, const RwV2d* viewWindow);
    static RwInt32 FRwEngineGetCurrentVideoMode();
    static RwVideoMode* FRwEngineGetVideoModeInfo(RwVideoMode* modeinfo, RwInt32 modeIndex);

    static RwMatrix* FRwMatrixScale(RwMatrix* matrix, const RwV3d* scale, RwOpCombineType combineOp);

    static RpClump* FRpClumpForAllAtomics(RpClump* clump, RpAtomicCallBack callback, void* pData);
    static int FRpSkinAtomicGetHAnimHierarchy(RpAtomic* atomic);
    static RwInt32 FRpHAnimIDGetIndex(RpHAnimHierarchy* hierarchy, RwInt32 ID);
    static RwMatrix* FRwFrameGetLTM(RwFrame* frame);
    static RpHAnimHierarchy* FGetAnimHierarchyFromSkinClump(RpClump* clump);

    static RpClump* FRpClumpGetBoundingSphere(RpClump* Clump, RwSphere* Sphere, bool UseLTM);
    static RpClump* FClumpRotate(RpClump* clump, RwCamera* camera, RwReal xAngle, RwReal yAngle);
    static RwBool FRpClumpDestroy(RpClump* clump);

    static RpClump* FRpClumpCreate();
    static void FRpClumpAddAtomic(RpClump* clump, RpAtomic* atomic);
    static RpClump* FRpClumpStreamRead(RwStream* stream);
    static RpClump* FRpClumpRender(RpClump* clump);
    static RpClump* FRpClumpClone(RpClump* clump);

    static void ApplyTXDToClump(RpClump* clump, RwTexDictionary* txd);

private:
    static RpAtomic* FGetAnimHierarchyCallback(RpAtomic* atomic, void* data);
    static RpAtomic* FAtomicAddBSphereCentre(RpAtomic* atomic, void* data);
    static RpAtomic* FAtomicCompareBSphere(RpAtomic* atomic, void* data);

    static RpAtomic* ApplyTXDToAtomicCallback(RpAtomic* atomic, void* data);
    static void ApplyTextureToMaterialCallback(RwTexture* texture, void* data);
};