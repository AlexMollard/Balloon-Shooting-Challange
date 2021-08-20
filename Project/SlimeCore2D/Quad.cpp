#include "Quad.h"

Quad::Quad() : GameObject()
{
}

Quad::~Quad()
{
}

void Quad::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void Quad::SetRadius(float rad)
{
	radius = rad; 
}

float Quad::GetRadius()
{
	return radius; 
}