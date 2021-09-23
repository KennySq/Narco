#pragma once
#include"Common.h"
#include"IFileSystem.h"

namespace NARCO
{
	class MeshLoader : IFileSystem
	{
	public:
		virtual void Load() override;
		virtual void Reload() override;
		virtual void Release() override;
	private:

		std::vector<XMFLOAT4> mPositions;
		std::vector<XMFLOAT4> mNormals;
		std::vector<XMFLOAT2> mTexcoords;

		std::vector<unsigned int> mIndices;


	};
}