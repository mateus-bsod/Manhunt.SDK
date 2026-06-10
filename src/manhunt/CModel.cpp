#include "CModel.h"

namespace CModel
{
	void LoadModel(DWORD* this_, void* modelName)
	{
		Call<0x59B7C0>(this_, modelName);
	}

	void UnloadModel(DWORD* this_)
	{
		Call<0x61B380>(this_);
	}
}