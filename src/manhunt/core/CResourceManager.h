#pragma once

#include "../../../framework.h"
#include "../../game.sdk.h"

#include "../ui/CVisual.h"

struct FileRegistryNode {
	FileRegistryNode* next;
	void* callback;
	void* pathStruct;
};


namespace CResourceManager
{

	void InitializeResource(void* dest, const char* src);
	int RegistryResource(FileRegistryNode* node, void* callback, void* pathStruct);

	// ----------------------------------------------------------------------------------------

	void InstallHook();
}