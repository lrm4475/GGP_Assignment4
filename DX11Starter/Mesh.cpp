#include <d3d11.h> //for Direct3D objs
#include "Mesh.h"
#include "Vertex.h"

// For the DirectX Math library
using namespace DirectX;

Mesh::Mesh(Vertex* vertices, int vInt, unsigned int* uIntindices, int iInt, ComPtr<ID3D11Device> deviceObj)
{
	//Create VBO description
	D3D11_BUFFER_DESC vbd;
	vbd.Usage = D3D11_USAGE_IMMUTABLE;
	vbd.ByteWidth = sizeof(Vertex) * vInt;       // vInt = number of vertices in buffer
	vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER; // Tells DirectX this is vertex buffer
	vbd.CPUAccessFlags = 0;
	vbd.MiscFlags = 0;
	vbd.StructureByteStride = 0;
	// Create struct to hold initial vertex data
	D3D11_SUBRESOURCE_DATA initialVertexData;
	initialVertexData.pSysMem = vertices;
	// Actually create vbo w/ initial data
	deviceObj->CreateBuffer(&vbd, &initialVertexData, vertexBuffer.GetAddressOf());

	//Create ibo description
	D3D11_BUFFER_DESC ibd;
	ibd.Usage = D3D11_USAGE_IMMUTABLE;
	ibd.ByteWidth = sizeof(unsigned int) * iInt;	// iInt = number of indices in the buffer
	ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;	// Tells DirectX this is an index buffer
	ibd.CPUAccessFlags = 0;
	ibd.MiscFlags = 0;
	ibd.StructureByteStride = 0;
	//Create struct to hold initial index data
	D3D11_SUBRESOURCE_DATA initialIndexData;
	initialIndexData.pSysMem = uIntindices;
	deviceObj->CreateBuffer(&ibd, &initialIndexData, indexBuffer.GetAddressOf());

	indices = iInt;
}

Mesh::~Mesh()
{
	//no Release()s needed for ComPtrs
}

ComPtr<ID3D11Buffer> Mesh::GetVertexBuffer()
{
	return vertexBuffer;
}

ComPtr<ID3D11Buffer> Mesh::GetIndexBuffer()
{
	return indexBuffer;
}

int Mesh::GetIndexCount()
{
	return indices;
}
