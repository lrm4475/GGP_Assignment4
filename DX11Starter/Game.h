#pragma once

#include "DXCore.h"
#include "Mesh.h"
#include "BufferStructs.h"
#include "Entity.h"

#include <DirectXMath.h>
#include <wrl/client.h> // Used for ComPtr - a smart pointer for COM objects

#include <iostream>
#include <memory>
#include <vector>

using namespace std;
using Microsoft::WRL::ComPtr;

class Game 
	: public DXCore
{

public:
	Game(HINSTANCE hInstance);
	~Game();

	vector<Entity> entities;


	// Overridden setup and game loop methods, which
	// will be called automatically
	void Init();
	void OnResize();
	void Update(float deltaTime, float totalTime);
	void Draw(float deltaTime, float totalTime);

private:

	// Initialization helper methods - feel free to customize, combine, etc.
	void LoadShaders(); 
	void CreateBasicGeometry();

	// Note the usage of ComPtr below
	//  - This is a smart pointer for objects that abide by the
	//    Component Object Model, which DirectX objects do
	//  - More info here: https://github.com/Microsoft/DirectXTK/wiki/ComPtr

	//MOVED FOR ASSIGNMENT 2
	// Buffers to hold actual geometry data
	//Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
	//Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;
	
	//Constant buffer
	Microsoft::WRL::ComPtr<ID3D11Buffer> constantBuffer;

	// Shaders and shader-related constructs
	Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;

};

