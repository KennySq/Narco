#pragma once
#include"Common.h"
#include"Narco_Common.h"

namespace NARCO
{
	class Mesh
	{
	public:
		Mesh();
		Mesh(const Mesh& mesh);
		Mesh(const Mesh&&) = delete;

		ID3D11Buffer* GetVertex() const { return mVertex.Get(); }
		ID3D11Buffer* GetIndex() const { return mIndex.Get(); }

	private:
		ComPtr<ID3D11Buffer> mVertex;
		ComPtr<ID3D11Buffer> mIndex;
	};
}