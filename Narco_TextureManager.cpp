#include"inc/Narco_TextureManager.h"

namespace NARCO
{
	void Narco_TextureManager::AddTexture2D(D3DTexture2D* p)
	{
		if (p == nullptr)
		{
			ExceptionError(E_INVALIDARG, "invalid address");
			return;
		}

		mListTexture2D.emplace_back(p);
	}
	void Narco_TextureManager::AddDepthStencil(D3DDepthStencil* p)
	{
		if (p == nullptr)
		{
			ExceptionError(E_INVALIDARG, "invalid address");
			return;
		}

		mListDepthStencils.emplace_back(p);

	}

	D3DTexture2D* Narco_TextureManager::GetTexture2D(unsigned int index)
	{
		if (index >= mListTexture2D.size() || index < 0)
		{
			ExceptionError(E_INVALIDARG, "invalid index");
			return nullptr;
		}
		return mListTexture2D[index];
	}
	D3DDepthStencil* Narco_TextureManager::GetDepthStencil(unsigned int index)
	{
		if (index >= mListDepthStencils.size() || index < 0)
		{
			ExceptionError(E_INVALIDARG, "invalid index");
			return nullptr;
		}

		return mListDepthStencils[index];
	}
}