#pragma once
#include"Common.h"
#include"Narco_Common.h"
#include"D3DUtil.h"

#include<atlbase.h>
#include<d3dcompiler.h>

#pragma comment(lib, "d3dcompiler.lib")

// #########################################################
// entry
//	- VS -> vert
//	- GS -> geom
//	- DS -> doma
//  - HS -> hull
//	- PS -> frag
// #########################################################

namespace NARCO
{
	enum eShaderFlag
	{
		SHADER_VERTEX = 1,
		SHADER_GEOMETRY = 2,
		SHADER_DOMAIN = 4,
		SHADER_HULL = 8,
		SHADER_PIXEL = 16,
		SHADER_COMPUTE = 0, // Independent
	};

	class Shader
	{
	public:
		Shader(const char* path, unsigned int flags);
		~Shader();

		HRESULT Compile(ID3D11Device* device);

		ID3D11VertexShader* GetVS() const { return mVertex.Get(); }
		ID3D11GeometryShader* GetGS() const { return mGeometry.Get(); }
		ID3D11DomainShader* GetDS() const { return mDomain.Get(); }
		ID3D11HullShader* GetHS() const { return mHull.Get(); }
		ID3D11PixelShader* GetPS() const { return mPixel.Get(); }

		void Release();
	private:
		eShaderFlag mFlags;

		std::string mPath;

		ComPtr<ID3D11VertexShader> mVertex = nullptr;
		ComPtr<ID3D11GeometryShader> mGeometry = nullptr;
		ComPtr<ID3D11DomainShader> mDomain = nullptr;
		ComPtr<ID3D11HullShader> mHull = nullptr;
		ComPtr<ID3D11PixelShader> mPixel = nullptr;
	};
}