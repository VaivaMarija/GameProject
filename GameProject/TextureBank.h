#pragma once
#include <SFML/Graphics/Texture.hpp>

class TextureBank
{
public:

	static sf::Texture projectileTexture;

	static void loadAllTextures()
	{
		projectileTexture.loadFromFile("Content/Textures/Lasers/laserGreen.png");
	}

};
