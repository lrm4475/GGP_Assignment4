#pragma once
#include <d3d11.h> //for Direct3D objs
#include <wrl/client.h> //for ComPtr
#include "Vertex.h" //for Vertex struct

using Microsoft::WRL::ComPtr;

class Mesh
{
public:
	//constructor - takes array of vbos, # of vertices in va, array of uints in ia, # of indices in ia, ptr to device obj
	Mesh(Vertex* vertices, int vInt, unsigned int* uIntindices, int iInt, ComPtr<ID3D11Device> deviceObj);
	//destructor
	~Mesh();

	//functions
	//returns ptr to vbo
	ComPtr<ID3D11Buffer> GetVertexBuffer();
	//returns ptr to ibo
	ComPtr<ID3D11Buffer> GetIndexBuffer();
	//returns # of indices in mesh's ibo
	int GetIndexCount();
private:

	// Buffers to hold geometry data
	ComPtr<ID3D11Buffer> vertexBuffer;
	ComPtr<ID3D11Buffer> indexBuffer;

	//int specifying # of indices in mesh's ibo
	int indices;
};

