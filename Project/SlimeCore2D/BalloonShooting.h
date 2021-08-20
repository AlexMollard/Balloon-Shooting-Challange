#pragma once
#include "ObjectManager.h"

class BalloonShooting
{
public:
	BalloonShooting(ObjectManager* objManager);
	~BalloonShooting();

	void Update(float deltaTime);

private:
	ObjectManager* objManager;

	GameObject* playerGun;
	GameObject* balloon;
};

