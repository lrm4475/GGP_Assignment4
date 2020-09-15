#pragma once
#include <DirectXMath.h>

class Transform
{
public:
	Transform();
	~Transform();

	//setters - overwrite transform values
	void SetPos(float x, float y, float z);
	void SetRot(float pitch, float yaw, float roll);
	void SetScale(float x, float y, float z);

	//getters - return value
	DirectX::XMFLOAT3 GetPosition();
	DirectX::XMFLOAT3 GetPitchYawRoll();
	DirectX::XMFLOAT3 GetScale();
	DirectX::XMFLOAT4X4 GetWorldMatrix();

	//transformation manipulation
	void MovePosAbs(float x, float y, float z);
	void Rotate(float pitch, float yaw, float roll);
	void Scale(float x, float y, float z);

private:
	bool old;
	DirectX::XMFLOAT4X4 worldMatrix; //entity's pos, rot, and scale

	DirectX::XMFLOAT3 position; //pos vect
	DirectX::XMFLOAT3 scale; //scale vect
	DirectX::XMFLOAT3 rotation; //rot quat
};

