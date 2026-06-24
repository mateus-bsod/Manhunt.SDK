#pragma once

#include "FakeRW.h"

// .text:005EEB48                 mov     ebp, g_CameraRW
RwCamera* FakeRW::GetCurrentCamera()
{
	return *(RwCamera**)0x7CF078;
}

RpWorld* FakeRW::GetCurrentWorld()
{
	return *(RpWorld**)0x715B8C;
}

// gta 3 - re
RpLight* pAmbient;
RwRGBAReal AmbientLightColourForFrame;
void FakeRW::SetAmbientColours()
{
	RpLightSetColor(pAmbient, &AmbientLightColourForFrame);
}

// ------------------------------------------------------------------

RpWorld* FakeRW::FRpWorldAddClump(RpWorld* world, RpClump* clump) {
	return CallAndReturn<RpWorld*, 0x61FBE0, RpWorld*, RpClump*>(world, clump);
}
RpWorld* FakeRW::FRpWorldRemoveClump(RpWorld* world, RpClump* clump) {
	return CallAndReturn<RpWorld*, 0x61FD40, RpWorld*, RpClump*>(world, clump);
}

RwBool FakeRW::FRpWorldDestroy(RpWorld* world)
{
	return CallAndReturn<RwBool, 0x616290, RpWorld*>(world);
}

RpWorld* FakeRW::FRpWorldCreate(RwBBox* boundingBox)
{
	return CallAndReturn<RpWorld*, 0x6163E0, RwBBox*>(boundingBox);
}

RpClump* FakeRW::FRpClumpRender(RpClump* clump)
{
	return CallAndReturn<RpClump*, 0x61ABF0, RpClump*>(clump);
}

RwReal FakeRW::FRwV3dLength(const RwV3d* in)
{
	return CallAndReturn<RwReal, 0x615430, const RwV3d*>(in);
}

RwModuleInfo& vectorModule = *(RwModuleInfo*)0x8227B0;

#define RWVECTORGLOBAL(var) (RWPLUGINOFFSET(rwVectorGlobals, RwEngineInstance, vectorModule.globalsOffset)->var)

typedef RwV3d* (*rwVectorMultFn) (RwV3d* pointOut,
	const RwV3d* pointIn,
	const RwMatrix* matrix);

typedef RwV3d* (*rwVectorsMultFn) (RwV3d* pointsOut,
	const RwV3d* pointsIn,
	RwInt32 numPoints,
	const RwMatrix* matrix);


typedef struct rwVectorGlobals rwVectorGlobals;
struct rwVectorGlobals
{
	RwSplitBits* SqrtTab;
	RwSplitBits* InvSqrtTab;


	rwVectorMultFn  multPoint;
	rwVectorsMultFn multPoints;
	rwVectorMultFn  multVector;
	rwVectorsMultFn multVectors;
};

RwV3d* FakeRW::FRwV3dTransformPoints(RwV3d* pointsOut, const RwV3d* pointsIn, RwInt32 numPoints, const RwMatrix* matrix)
{
	return RWVECTORGLOBAL(multPoints)(pointsOut, pointsIn, numPoints, matrix);
}

RwMatrix* FakeRW::FRwMatrixInvert(RwMatrix* matrixOut, const RwMatrix* matrixIn)
{
	return CallAndReturn<RwMatrix*, 0x619880, RwMatrix*, const RwMatrix*>(matrixOut, matrixIn);
}

void FakeRW::F_rpAtomicResyncInterpolatedSphere(RpAtomic* atomic)
{
	return Call<0x61A390, RpAtomic*>(atomic);
}

void FakeRW::FCameraSize(RwCamera* camera, RwRect* rect, RwReal viewWindow, RwReal aspectRatio)
{
	RwVideoMode         videoMode;
	RwRect              r;
	RwRect              origSize = { 0, 0, 0, 0 };	// FIX just to make the compier happy
	RwV2d               vw;

	viewWindow *= aspectRatio;

	RwEngineGetVideoModeInfo(&videoMode, RwEngineGetCurrentVideoMode());

	origSize.w = RwRasterGetWidth(RwCameraGetRaster(camera));
	origSize.h = RwRasterGetHeight(RwCameraGetRaster(camera));


	if (!rect)
	{
		if (videoMode.flags & rwVIDEOMODEEXCLUSIVE)
		{
			/* For full screen applications, resizing the camera just doesn't
			 * make sense, use the video mode size.
			 */

			r.x = r.y = 0;
			r.w = videoMode.width;
			r.h = videoMode.height;
			rect = &r;
		}
		else
		{
			/*
			rect not specified - reuse current values
			*/
			r.w = RwRasterGetWidth(RwCameraGetRaster(camera));
			r.h = RwRasterGetHeight(RwCameraGetRaster(camera));
			r.x = r.y = 0;
			rect = &r;
		}
	}

	if (videoMode.flags & rwVIDEOMODEEXCLUSIVE)
	{
		/* derive ratio from aspect ratio */
		vw.x = viewWindow;
		vw.y = viewWindow / aspectRatio;
	}
	else
	{
		/* derive from pixel ratios */
		if (rect->w > rect->h)
		{
			vw.x = viewWindow;
			vw.y = (rect->h * viewWindow) / rect->w;
		}
		else
		{
			vw.x = (rect->w * viewWindow) / rect->h;
			vw.y = viewWindow;
		}
	}

	RwCameraSetViewWindow(camera, &vw);
}

RwStream* FakeRW::FRwStreamOpen(RwStreamType type, RwStreamAccessType accessType, const void* pData)
{
	return CallAndReturn<RwStream*, 0x6121A0, RwStreamType, RwStreamAccessType, const void*>(type, accessType, pData);
}
RwBool FakeRW::FRwStreamFindChunk(RwStream* stream, RwUInt32 type, RwUInt32* lengthOut, RwUInt32* versionOut)
{
	return CallAndReturn<RwBool, 0x63C420, RwStream*, RwUInt32, RwUInt32*, RwUInt32*>(stream, type, lengthOut, versionOut);
}

RwBool FakeRW::FRwStreamClose(RwStream* stream, void* pData)
{
	return CallAndReturn<RwBool, 0x6120D0, RwStream*, void*>(stream, pData);
}

RwFrame* FakeRW::FRwFrameTransform(RwFrame* frame, const RwMatrix* m, RwOpCombineType combine)
{
	return CallAndReturn<RwFrame*, 0x618900, RwFrame*, const RwMatrix*, RwOpCombineType>(frame, m, combine);
}

RwFrame* FakeRW::FRwFrameTranslate(RwFrame* frame, const RwV3d* v, RwOpCombineType combine)
{
	return CallAndReturn<RwFrame*, 0x618860, RwFrame*, const RwV3d*, RwOpCombineType>(frame, v, combine);
}

RwFrame* FakeRW::FRwFrameUpdateObjects(RwFrame* frame)
{
	return CallAndReturn<RwFrame*, 0x618440, RwFrame*>(frame);
}
RwFrame* FakeRW::FRwFrameRotate(RwFrame* frame, const RwV3d* axis, RwReal angle, RwOpCombineType combine)
{
	return CallAndReturn<RwFrame*, 0x6189A0, RwFrame*, const RwV3d*, RwReal, RwOpCombineType>(frame, axis, angle, combine);
}
RwCamera* FakeRW::FRwCameraBeginUpdate(RwCamera* camera)
{
	return CallAndReturn<RwCamera*, 0x6260E0, RwCamera*>(camera);
}
RwCamera* FakeRW::FRwCameraEndUpdate(RwCamera* camera)
{
	return CallAndReturn<RwCamera*, 0x6260D0, RwCamera*>(camera);
}

RwCamera* FakeRW::FRwCameraCreate()
{
	return CallAndReturn<RwCamera*, 0x626410>();
}

RpLight* FakeRW::FRpLightCreate(RwInt32 type)
{
	return CallAndReturn<RpLight*, 0x621740, RwInt32>(type);
}

RpLight* FakeRW::FRpLightSetColor(RpLight* light, const RwRGBAReal* color)
{
	return CallAndReturn<RpLight*, 0x6211B0, RpLight*, const RwRGBAReal*>(light, color);
}

RpLight* FakeRW::FRpLightSetRadius(RpLight* light, RwReal radius)
{
	return CallAndReturn<RpLight*, 0x621190, RpLight*, RwReal>(light, radius);
}

RpLight* FakeRW::FRpLightSetConeAngle(RpLight* light, RwReal angle)
{
	return CallAndReturn<RpLight*, 0x621440, RpLight*, RwReal>(light, angle);
}

RwReal FakeRW::FRpLightGetConeAngle(RpLight* light)
{
	return CallAndReturn<RwReal, 0x621200, RpLight*>(light);
}

RpWorld* FakeRW::FRpWorldAddLight(RpWorld* world, RpLight* light)
{
	return CallAndReturn<RpWorld*, 0x61FFA0, RpWorld*, RpLight*>(world, light);
}

RpWorld* FakeRW::FRpWorldRemoveLight(RpWorld* world, RpLight* light)
{
	return CallAndReturn<RpWorld*, 0x61FFF0, RpWorld*, RpLight*>(world, light);
}

RpLight* FakeRW::FRpLightSetDirection(RpLight* light, const RwV3d* direction)
{
	RwFrame* frame = RpLightGetFrame(light);
	if (frame) {
		RwMatrix* matrix = RwFrameGetMatrix(frame);
		if (matrix) {
			RwV3d normalized = *direction;
			RwV3dNormalize(&normalized, &normalized);
			*RwMatrixGetAt(matrix) = normalized;
		}
	}
	return light;
}

RwCamera* FakeRW::FRwCameraSetViewWindow(RwCamera* camera, const RwV2d* viewWindow)
{
	return CallAndReturn<RwCamera*, 0x626360, RwCamera*, const RwV2d*>(camera, viewWindow);
}

RwInt32 FakeRW::FRwEngineGetCurrentVideoMode()
{
	return CallAndReturn<RwInt32, 0x612740>();
}

RwVideoMode* FakeRW::FRwEngineGetVideoModeInfo(RwVideoMode* modeinfo, RwInt32 modeIndex)
{
	return CallAndReturn<RwVideoMode*, 0x612710, RwVideoMode*, RwInt32>(modeinfo, modeIndex);
}

RwBool FakeRW::FRpClumpDestroy(RpClump* clump)
{
	return CallAndReturn<RwBool, 0x61B380, RpClump*>(clump);
}

RwBool FakeRW::FRpLightDestroy(RpLight* light)
{
	return CallAndReturn<RwBool, 0x621700, RpLight*>(light);
}

RwMatrix* FakeRW::FRwMatrixScale(RwMatrix* matrix, const RwV3d* scale, RwOpCombineType combineOp)
{
	return CallAndReturn<RwMatrix*, 0x619AD0, RwMatrix*, const RwV3d*, RwOpCombineType>(matrix, scale, combineOp);
}

RpClump* FakeRW::FRpClumpForAllAtomics(RpClump* clump, RpAtomicCallBack callback, void* pData)
{
	return CallAndReturn<RpClump*, 0x61AC40, RpClump*, RpAtomicCallBack, void*>(clump, callback, pData);
}

int FakeRW::FRpSkinAtomicGetHAnimHierarchy(RpAtomic* atomic)
{
	return *(int*)(0x824A1C + atomic);
}

RpAtomic* FakeRW::FGetAnimHierarchyCallback(RpAtomic* atomic, void* data)
{
	*(RpHAnimHierarchy**)data = (RpHAnimHierarchy*)RpSkinAtomicGetHAnimHierarchy(atomic);
	return nullptr;
}

RwInt32 FakeRW::FRpHAnimIDGetIndex(RpHAnimHierarchy* hierarchy, RwInt32 ID)
{
	return CallAndReturn<RwInt32, 0x617250, RpHAnimHierarchy*, RwInt32>(hierarchy, ID);
}

RwMatrix* FakeRW::FRwFrameGetLTM(RwFrame* frame)
{
	return CallAndReturn<RwMatrix*, 0x6184C0, RwFrame*>(frame);
}

RpHAnimHierarchy* FakeRW::FGetAnimHierarchyFromSkinClump(RpClump* clump)
{
	RpHAnimHierarchy result;
	RpClumpForAllAtomics(clump, FGetAnimHierarchyCallback, &result);
	return &result;
}


static RwV3d Zero = { 0.0f, 0.0f, 0.0f };

RpAtomic* FakeRW::FAtomicAddBSphereCentre(RpAtomic* atomic, void* data)
{
	RpGeometry* geometry;

	geometry = RpAtomicGetGeometry(atomic);

	if (geometry)
	{
		RwV3d center;
		RwMatrix* LTM;
		RpMorphTarget* morphTarget;
		RwInt32 i, numMorphTargets;
		RwV3d atomicCentre;
		RwSphere* clumpSphere;

		clumpSphere = (RwSphere*)data;

		/*
		 * Establish the average centre of this atomic over all morph targets
		 */
		atomicCentre = Zero;

		numMorphTargets = RpGeometryGetNumMorphTargets(geometry);

		for (i = 0; i < numMorphTargets; i++)
		{
			morphTarget = RpGeometryGetMorphTarget(geometry, i);
			center = RpMorphTargetGetBoundingSphere(morphTarget)->center;
			RwV3dAdd(&atomicCentre, &atomicCentre, &center);
		}

		RwV3dScale(&atomicCentre, &atomicCentre, 1.0f / numMorphTargets);

		/*
		 * Tranform the average centre of the atomic to world space
		 */
		LTM = RwFrameGetLTM(RpAtomicGetFrame(atomic));
		RwV3dTransformPoints(&atomicCentre, &atomicCentre, 1, LTM);

		/*
		 * Add the average centre of the atomic up in order to calculate the centre of the clump
		 */
		RwV3dAdd(&clumpSphere->center, &clumpSphere->center, &atomicCentre);
	}

	return atomic;
}

RpAtomic* FakeRW::FAtomicCompareBSphere(RpAtomic* atomic, void* data)
{
	RpGeometry* geometry;

	geometry = RpAtomicGetGeometry(atomic);

	if (geometry)
	{
		RwSphere* sphere, morphTargetSphere;
		RwV3d tempVec;
		RpMorphTarget* morphTarget;
		RwReal dist;
		RwMatrix* LTM;
		RwInt32 i, numMorphTargets;

		sphere = (RwSphere*)data;

		LTM = RwFrameGetLTM(RpAtomicGetFrame(atomic));

		numMorphTargets = RpGeometryGetNumMorphTargets(geometry);

		for (i = 0; i < numMorphTargets; i++)
		{
			morphTarget = RpGeometryGetMorphTarget(geometry, i);
			morphTargetSphere = *RpMorphTargetGetBoundingSphere(morphTarget);

			RwV3dTransformPoints(&morphTargetSphere.center,
				&morphTargetSphere.center, 1, LTM);

			RwV3dSub(&tempVec, &morphTargetSphere.center, &sphere->center);

			dist = RwV3dLength(&tempVec) + morphTargetSphere.radius;
			if (dist > sphere->radius)
			{
				sphere->radius = dist;
			}
		}
	}

	return atomic;
}


RpClump* FakeRW::FRpClumpGetBoundingSphere(RpClump* Clump, RwSphere* Sphere, bool UseLTM)
{
	RwMatrix matrix;
	RwSphere sphere = { 0.0f, 0.0f, 0.0f, 0.0f };

	if (Clump == NULL || Sphere == NULL)
		return NULL;

	Sphere->radius = 0.0f;
	Sphere->center.x = 0.0f;
	Sphere->center.y = 0.0f;
	Sphere->center.z = 0.0f;

	RpClumpForAllAtomics(Clump, FAtomicAddBSphereCentre, &sphere);

	RwV3dScale(&sphere.center, &sphere.center, 1.0f);

	RpClumpForAllAtomics(Clump, FAtomicCompareBSphere, &sphere);

	RwMatrixInvert(&matrix, RwFrameGetLTM(RpClumpGetFrame(Clump)));

	RwV3dTransformPoints(&sphere.center, &sphere.center, 1, &matrix);

	RwSphereAssign(Sphere, &sphere);

	return Clump;
}

RpClump* FakeRW::FClumpRotate(RpClump* clump, RwCamera* camera, RwReal xAngle, RwReal yAngle)
{
	RwFrame* clumpFrame = NULL;
	RwFrame* cameraFrame = NULL;
	RwMatrix* cameraMatrix = NULL;
	RwMatrix* clumpMatrix = NULL;
	RwSphere ClumpSphere;

	RwV3d right, up, pos;

	/*
	 * Rotate clump about it's origin...
	 */
	clumpFrame = RpClumpGetFrame(clump);
	cameraFrame = RwCameraGetFrame(camera);

	clumpMatrix = RwFrameGetMatrix(clumpFrame);
	cameraMatrix = RwFrameGetMatrix(cameraFrame);

	right = *RwMatrixGetRight(cameraMatrix);
	up = *RwMatrixGetUp(cameraMatrix);

	//pos = *RwMatrixGetPos(clumpMatrix);

	FRpClumpGetBoundingSphere(clump, &ClumpSphere, false);

	RwV3dTransformPoints(&pos, &(ClumpSphere.center), 1, RwFrameGetLTM(clumpFrame));

	/*
	 * Translate back to the origin...
	 */
	RwV3dScale(&pos, &pos, -1.0f);
	RwFrameTranslate(clumpFrame, &pos, rwCOMBINEPOSTCONCAT);

	/*
	 * Do the rotation...
	 */
	RwFrameRotate(clumpFrame, &up, xAngle, rwCOMBINEPOSTCONCAT);
	RwFrameRotate(clumpFrame, &right, yAngle, rwCOMBINEPOSTCONCAT);

	/*
	 * And translate back...
	 */
	RwV3dScale(&pos, &pos, -1.0f);
	RwFrameTranslate(clumpFrame, &pos, rwCOMBINEPOSTCONCAT);

	return clump;
}

RpMaterial* FakeRW::FRpMaterialSetTexture(RpMaterial* material, RwTexture* texture)
{
	return CallAndReturn<RpMaterial*, 0x63D3F0, RpMaterial*, RwTexture*>(material, texture);
}


void FakeRW::FRpGeometryLock(RpGeometry* geometry, RwInt32 lockMode) {
	CallAndReturn<RpGeometry*, 0x631BE0, RpGeometry*, RwInt32>(geometry, lockMode);
}

void FakeRW::FRpGeometryUnlock(RpGeometry* geometry) {
	CallAndReturn<RpGeometry*, 0x631C10, RpGeometry*>(geometry);
}


RpAtomic* FakeRW::FRpAtomicSetGeometry(RpAtomic* atomic, RpGeometry* geometry, RwUInt32 flags) {

	return CallAndReturn<RpAtomic*, 0x61AE10, RpAtomic*, RpGeometry*, RwUInt32>(atomic, geometry, flags);
}

//
// txd 
// 

// Carrega TXD de um stream
RwTexDictionary* FakeRW::FRwTexDictionaryStreamRead(RwStream* stream) {
	return CallAndReturn<RwTexDictionary*, 0x0063CA20, RwStream*>(stream);
}

// Define o TXD como atual
void FakeRW::FRwTexDictionarySetCurrent(RwTexDictionary* dict) {
	CallAndReturn<void, 0x0062F6E0, RwTexDictionary*>(dict);
	// Ou se for o endereço decorado: 0x005C1A30
}

// Pega o TXD atual
RwTexDictionary* FakeRW::FRwTexDictionaryGetCurrent() {
	return CallAndReturn<RwTexDictionary*, 0x0062F700>();
}

// Destroi o TXD
void FakeRW::FRwTexDictionaryDestroy(RwTexDictionary* dict) {
	CallAndReturn<void, 0x0062F340, RwTexDictionary*>(dict);
	// Ou 0x005EE360 se for o decorado
}

// Adiciona textura ao TXD
void FakeRW::FRwTexDictionaryAddTexture(RwTexDictionary* dict, RwTexture* texture) {
	CallAndReturn<void, 0x0062F620, RwTexDictionary*, RwTexture*>(dict, texture);
}

// Cria um novo TXD
RwTexDictionary* FakeRW::FRwTexDictionaryCreate() {
	return CallAndReturn<RwTexDictionary*, 0x0062F2A0>();
}

// Itera sobre todas as texturas do TXD
RwTexDictionary* FakeRW::FRwTexDictionaryForAllTextures(const RwTexDictionary* dict, RwTextureCallBack fpCallBack, void* pData) {
	return CallAndReturn<RwTexDictionary*, 0x0062F3D0, const RwTexDictionary*, RwTextureCallBack, void*>(dict, fpCallBack, pData);
}

// 
// clump
//


// Cria um novo clump
RpClump* FakeRW::FRpClumpCreate() {
	return CallAndReturn<RpClump*, 0x0061B300>();
}

// Adiciona atomic ao clump

void FakeRW::FRpClumpAddAtomic(RpClump* clump, RpAtomic* atomic) {
	CallAndReturn<void, 0x0061B500, RpClump*, RpAtomic*>(clump, atomic);
}

// Lê clump do stream
RpClump* FakeRW::FRpClumpStreamRead(RwStream* stream) {
	return CallAndReturn<RpClump*, 0x0061C1B0, RwStream*>(stream);
}


// Clone do clump
RpClump* FakeRW::FRpClumpClone(RpClump* clump) {
	return CallAndReturn<RpClump*, 0x0061B020, RpClump*>(clump);
}


//

RwTexDictionary* FakeRW::LoadTXD(const char* filePath) {
	if (!filePath) return nullptr;

	RwStream* stream = FRwStreamOpen(rwSTREAMFILENAME, rwSTREAMREAD, filePath);
	if (!stream) {
		printf("Failed to open TXD file: %s\n", filePath);
		return nullptr;
	}

	RwTexDictionary* txd = nullptr;

	if (FRwStreamFindChunk(stream, 0x16, NULL, NULL)) {
		txd = FRwTexDictionaryStreamRead(stream);
		if (txd) {
			printf("TXD loaded successfully: %s\n", filePath);
		}
		else {
			printf("Failed to read TXD from stream: %s\n", filePath);
		}
	}
	else {
		printf("TXD chunk not found: %s\n", filePath);
	}
	FRwStreamClose(stream, NULL);

	return txd;
}

