#include "Entity.h"

Entity::Entity(std::unique_ptr<Mesh> meshPtr)
{
	ptr = std::move(meshPtr);
}

Entity::~Entity()
{
}

Mesh* Entity::GetMesh()
{
	return ptr.get();
}

Transform* Entity::GetTransform()
{
	return &transform;
}

//void Entity::Draw()
//{
//}


