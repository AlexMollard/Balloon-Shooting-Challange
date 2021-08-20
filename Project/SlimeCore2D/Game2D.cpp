#include "Game2D.h"

Game2D::Game2D()
{
	Init();

}

Game2D::~Game2D()
{
	delete physicsScene;
	physicsScene = nullptr;

	delete objectManager;
	objectManager = nullptr;
}

void Game2D::Init()
{
	camera = new Camera(-16, -9, -1, 1);
	renderer = new Renderer2D(camera);
	objectManager = new ObjectManager(renderer);
	physicsScene = new PhysicsScene();
	Input::GetInstance()->SetCamera(camera);
	objectManager->CreateGameObject(glm::vec3(0), glm::vec2(2), glm::uvec3(1, 0, 1));
}

void Game2D::Update(float deltaTime)
{
	camera->Update(deltaTime);
	physicsScene->update(deltaTime);
	objectManager->UpdateFrames(deltaTime);
}

void Game2D::Draw()
{
	renderer->Draw();
}