//for necessary math, this library:
#include <DirectXMath.h>
#pragma once

struct VertexShaderExternalData
{
	DirectX::XMFLOAT4 colorTint;
	DirectX::XMFLOAT4X4 worldMatrix;
};