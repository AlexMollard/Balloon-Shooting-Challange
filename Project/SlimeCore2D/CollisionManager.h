#pragma once
#include "RigidBody.h"
#include "Quad.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	static glm::vec2 QuadVsQuad(RigidBody* rbOne, RigidBody* rbTwo);

	static glm::vec2 CircleVsCircle(RigidBody* rbOne, RigidBody* rbTwo); 
};
