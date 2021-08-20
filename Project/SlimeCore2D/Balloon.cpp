#include "Balloon.h"
#include "gtc/random.hpp"
Balloon::Balloon(GameObject* obj)
{
    object = obj;
}

Balloon::~Balloon()
{

}

void Balloon::Update(float deltaTime)
{
    MovePos(deltaTime);
}

void Balloon::MovePos(float deltaTime)
{
    float currentY = object->GetPos().y;
    if (glm::distance(currentY, targetY) <= 1.0f)
    {
        targetY = GetNewLocation();

        if (currentY < targetY)
            object->SetVelocity(glm::vec2(0.0f,velocity));
        else
            object->SetVelocity(glm::vec2(0.0f,-velocity));
    }

}

float Balloon::GetNewLocation()
{
    return glm::linearRand(-8.0f, 8.0f);
}
