#pragma once
#include"D3DTexture2D.h"
#include"D3DDepthStencil.h"

#include<vector>

using namespace NARCO;

namespace NARCO
{
	class Narco_TextureManager
	{
	public:
		void AddTexture2D(D3DTexture2D* p);
		void AddDepthStencil(D3DDepthStencil* p);

		D3DTexture2D* GetTexture2D(unsigned int index);
		D3DDepthStencil* GetDepthStencil(unsigned int index);


	private:
		std::vector<D3DTexture2D*> mListTexture2D;
		std::vector<D3DDepthStencil*> mListDepthStencils;
	};
}