#include "BalloonShooting.h"

BalloonShooting::BalloonShooting(ObjectManager* objManager)
{
	this->objManager = objManager;
	playerGun = objManager->CreateGameObject(glm::vec3(11, 0, 0), glm::vec2(1,1), glm::vec3(0.3f,0.3f,0.3f));
	balloon = objManager->CreateGameObject(glm::vec3(-11, 0, 0), glm::vec2(1,1), glm::vec3(0.9f,0.3f,0.3f));
	Texture* tex = new Texture("../Images/circle.png");
	balloon->SetTexture(tex);
}

BalloonShooting::~BalloonShooting()
{

}

void BalloonShooting::Update(float deltaTime)
{
	static float balloonYPos = 0;
	static float iteration = 0;
	static float playerSpeed = 12;

	iteration += deltaTime;

	balloonYPos = glm::cos(iteration) * 8;
	balloon->SetPos(glm::vec3(-11, balloonYPos, 0));

	if (Input::GetKeyPress(Keycode::UP))
	{
		playerGun->SetPos(playerGun->GetPos() + glm::vec3(0,(playerSpeed * deltaTime),0));
	}

	if (Input::GetKeyPress(Keycode::DOWN))
	{
		playerGun->SetPos(playerGun->GetPos() + glm::vec3(0, (-playerSpeed * deltaTime),0));
	}
}
