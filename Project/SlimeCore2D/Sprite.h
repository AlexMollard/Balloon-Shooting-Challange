#pragma once
#include "Texture.h"
class Sprite : public Texture
{
public:
	Sprite(std::string dir, int SpriteWidth, int SpriteHeight);
	~Sprite();

};
