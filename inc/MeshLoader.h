#pragma once
#include"Common.h"
#include"Narco_Common.h"
#include"IFileSystem.h"

#include"Mesh.h"

namespace NARCO
{
	enum eMeshType
	{
		MESH_NONE,
		MESH_FBX,
		MESH_OBJ,
	};

	class MeshLoader : IFileSystem
	{
	public:
		MeshLoader(ID3D11Device* device) : mDevice(device), mVertexType(VERTEX_STATIC), mMeshType(MESH_NONE) {}
		virtual ~MeshLoader() {}
		virtual void SetPath(const char* path) override;
		virtual void Load() override;
		virtual void Reload() override;
		virtual void Release() override;
		Mesh* ConvertMesh() const;

	private:
		bool fbx_loadFbx();
		void fbx_loadNode(FbxNode* node);
		void fbx_getControlPoints(FbxMesh* mesh);
		void fbx_toVertex(const XMFLOAT3& position, const XMFLOAT3& normal, const XMFLOAT3& binormal, const XMFLOAT3& tangent, const XMFLOAT2& texcoord);
		XMFLOAT3 fbx_getNormal(const FbxMesh* mesh, int controlPoint, int vertex);
		XMFLOAT3 fbx_getBinormals(const FbxMesh* mesh, int controlPoint, int vertex);
		XMFLOAT3 fbx_getTangents(const FbxMesh* mesh, int controlPoint, int vertex);
		XMFLOAT2 fbx_getTexcoords(const FbxMesh* mesh, int controlPoint, int texcoordIndex);

		std::string mPath;
		eMeshType mMeshType;
		eVertexType mVertexType;

		std::vector<XMFLOAT3> mPositions;
		std::vector<XMFLOAT3> mNormals;
		std::vector<XMFLOAT3> mBinormals;
		std::vector<XMFLOAT3> mTangents;
		std::vector<XMFLOAT2> mTexcoords;

		std::vector<Vertex_Static> mVertices;
		std::vector<unsigned int> mIndices;
		

		ID3D11Device* mDevice;

	//	std::unordered_map<Vertex_Static, unsigned int> mIndexMapping;
	};
}

