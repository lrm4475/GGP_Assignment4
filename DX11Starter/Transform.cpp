#include "Transform.h"

using namespace DirectX;

Transform::Transform()
{
	XMStoreFloat4x4(&worldMatrix, XMMatrixIdentity());

	position = XMFLOAT3(0, 0, 0);
	rotation = XMFLOAT3(0, 0, 0);
	scale = XMFLOAT3(1, 1, 1);

	old = false; //just created
}

Transform::~Transform()
{
}

void Transform::SetPos(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;

	old = true;
}

void Transform::SetRot(float pitch, float yaw, float roll)
{
	rotation.x = pitch;
	rotation.y = yaw;
	rotation.z = roll;

	old = true;
}

void Transform::SetScale(float x, float y, float z)
{
	scale.x = x;
	scale.y = y;
	scale.z = z;

	old = true;
}

DirectX::XMFLOAT3 Transform::GetPosition()
{
	return position;
}

DirectX::XMFLOAT3 Transform::GetPitchYawRoll()
{
	return rotation;
}

DirectX::XMFLOAT3 Transform::GetScale()
{
	return scale;
}

DirectX::XMFLOAT4X4 Transform::GetWorldMatrix()
{
	if (old) { //recalc if necessary
		XMMATRIX pos_T = XMMatrixTranslationFromVector(XMLoadFloat3(&position));
		XMMATRIX rot_T = XMMatrixRotationRollPitchYawFromVector(XMLoadFloat3(&rotation));
		XMMATRIX scale_T = XMMatrixScalingFromVector(XMLoadFloat3(&scale));

		XMMATRIX temp = scale_T * rot_T * pos_T;
		XMStoreFloat4x4(&worldMatrix, temp);

		old = false; //just recalculated
	}

	return worldMatrix;
}

void Transform::MovePosAbs(float x, float y, float z)
{
	position.x += x;
	position.y += y;
	position.z += z;

	old = true;
}

void Transform::Rotate(float pitch, float yaw, float roll)
{
	rotation.x += pitch;
	rotation.y += yaw;
	rotation.z += roll;

	old = true;
}

void Transform::Scale(float x, float y, float z)
{
	scale.x *= x;
	scale.y *= y;
	scale.z *= z;

	old = true;
}
