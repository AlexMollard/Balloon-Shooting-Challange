#pragma once
#include "glm.hpp"
#include "GameObject.h"
class Balloon
{
public:
	Balloon(GameObject* obj);
	~Balloon();

	void Update(float deltaTime);
	void MovePos(float deltaTime);
	float GetNewLocation();

	float GetSpeed() { return velocity; };
private:
	GameObject* object;

	float velocity = 5.0f;
	float targetY = 0.0f;
};

