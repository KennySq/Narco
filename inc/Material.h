#pragma once
#include"Common.h"
#include"Narco_Common.h"
#include"D3DUtil.h"
#include"Shader.h"

namespace NARCO
{
	class Material
	{
	public:
		Material();
		~Material();

	private:

		ComPtr<ID3D11RasterizerState> mRasterState;
		ComPtr<ID3D11DepthStencilState> mDepthState;
	//	ComPtr<ID3D11Buffer>
		//ComPtr<ID3D11ShaderResourceView> mShaderResources;

		std::string mPath;
		Shader* mShader;
	};
}