#include "BalloonShooting.h"
#include <iostream>
#include <string>

BalloonShooting::BalloonShooting(ObjectManager* objManager, PhysicsScene* physicsScene)
{
	this->objManager = objManager;
	pScene = physicsScene;

	playerGun = objManager->CreateGameObject(glm::vec3(14, 0, 0), glm::vec2(1,1), glm::vec3(0.3f,0.3f,0.3f));
	playerGunBarrel = objManager->CreateGameObject(glm::vec3(13.5f, 0, 0), glm::vec2(0.5f,0.4f), glm::vec3(0.3f,0.3f,0.3f));
	balloonObject = objManager->CreateGameObject(glm::vec3(-14, 0, 0), glm::vec2(1,1), glm::vec3(0.8f,0.2f,0.2f));
	bullet = objManager->CreateGameObject(glm::vec3(50.0f),glm::vec2(0.25f), glm::vec3(1.0f));
	bullet->SetBoundingBox(glm::vec2(0), glm::vec2(0.3f));

	tex = new Sprite("../Images/circle.png",32,32);
	balloonObject->SetTexture(tex);
	balloonObject->SetHasAnimation(false);
	balloonObject->SetSpriteWidth(32);
	balloonObject->SetScale(glm::vec2(1.0f));
	balloonObject->SetBoundingBox(glm::vec2(0), glm::vec2(1));

	pScene->addActor(bullet, "bullet", false);
	pScene->addActor(balloonObject, "balloon", true);
	balloon = new Balloon(balloonObject);
	
	textShader = new Shader("Text Shader", "textVert.shader", "textFrag.shader");
	textDisplay = new Text();
}

BalloonShooting::~BalloonShooting()
{
	delete tex;
	tex = nullptr;

	delete balloon;
	balloon = nullptr;

	delete textDisplay;
	textDisplay = nullptr;

	delete textShader;
	textShader = nullptr;
}

void BalloonShooting::Update(float deltaTime)
{
	balloon->Update(deltaTime);
	shotCoolDown -= deltaTime;

	static float playerSpeed = 12;

	if ((Input::GetKeyPress(Keycode::UP) || Input::GetKeyPress(Keycode::W)) && playerGun->GetPos().y < 8.5f)
	{
		playerGun->SetPos(playerGun->GetPos() + glm::vec3(0,(playerSpeed * deltaTime),0));
		playerGunBarrel->SetPos(playerGunBarrel->GetPos() + glm::vec3(0,(playerSpeed * deltaTime),0));
	}

	if ((Input::GetKeyPress(Keycode::DOWN) || Input::GetKeyPress(Keycode::S)) && playerGun->GetPos().y > -8.5f)
	{
		playerGun->SetPos(playerGun->GetPos() + glm::vec3(0, (-playerSpeed * deltaTime),0));
		playerGunBarrel->SetPos(playerGunBarrel->GetPos() + glm::vec3(0, (-playerSpeed * deltaTime),0));
	}

	if ((Input::GetKeyPress(Keycode::SPACE) || Input::GetKeyPress(Keycode::A) || Input::GetKeyPress(Keycode::LEFT)) && shotCoolDown <= 0.0f)
	{
		shotCoolDown = 0.85f;
		attempts++;
		bullet->SetPos(playerGun->GetPos());
		bullet->SetVelocity(glm::vec2((-balloon->GetSpeed() * 10.0f),0.0f));
	}

	if (balloonObject->GetLastHitRigidBody() != nullptr && youWon == false)
	{
		youWon = true;
		hitAttempt = attempts;
	}

	if (youWon)
		textDisplay->RenderText(*textShader, "You hit the balloon in " + std::to_string(hitAttempt) + " Attempts.", 0, 62, 0.80f, glm::vec3(1.0f));
	
	textDisplay->RenderText(*textShader, "Current Attempts: " + std::to_string(attempts), 0, 12, 0.8f, glm::vec3(1.0f));
}
