#pragma once
#include "ObjectManager.h"
#include "PhysicsScene.h"
#include "Sprite.h"
#include "Balloon.h"
#include "Text.h"
#include "Shader.h"

class BalloonShooting
{
public:
	BalloonShooting(ObjectManager* objManager, PhysicsScene* physicsScene);
	~BalloonShooting();

	void Update(float deltaTime);

private:
	int attempts = 0;
	int hitAttempt = 0;
	float shotCoolDown = 0.0f;
	bool youWon = false;

	ObjectManager* objManager;
	PhysicsScene* pScene;

	Balloon* balloon;
	Sprite* tex;
	GameObject* playerGun;
	GameObject* playerGunBarrel;
	GameObject* balloonObject;
	GameObject* bullet;

	Shader* textShader;
	Text* textDisplay;
};

