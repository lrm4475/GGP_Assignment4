#pragma once
#include <memory>
#include "Transform.h"
#include "Mesh.h"

class Entity
{
public:
	Entity(std::unique_ptr<Mesh> ptr);
	~Entity();

	//getters 
	Mesh* GetMesh();
	Transform* GetTransform();

	//methods
	//void Draw();

private:
	Transform transform;
	std::unique_ptr<Mesh> ptr;
};

