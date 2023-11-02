#include "Asteroids.h"
#include "TextureBank.h"

void Asteroids::Load()
{
	texture.loadFromFile("Content/Textures/Meteors/MeteorBrown_med1.png");
	sprite.setTexture(texture);

	//set sprite origin to be in the centre of itself, so it rotates on the centre
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}

void Asteroids::Tick(float _deltaTime)
{
	sf::Vector2f asteroidSpeed(2, 10);
	asteroidSpeed *= 10.0f;
	sf::Vector2f ASpeed = asteroidSpeed * _deltaTime;
	sprite.move(ASpeed);

	if (sprite.getPosition().y > 950)
	{
		setPosition(sf::Vector2f((rand() % 1200) + 100, 0));

		int randomTextureA = rand() % 4;

		if (randomTextureA == 0)
		{
			sprite.setTexture(CTextureBank::meteorBigT, true);
		}
		if (randomTextureA == 1)
		{
			sprite.setTexture(CTextureBank::meteorMediumT, true);
		}
		if (randomTextureA == 2)
		{
			sprite.setTexture(CTextureBank::meteorSmallT, true);
		}
		if (randomTextureA == 3)
		{
			sprite.setTexture(CTextureBank::meteorTinyT, true);
		}

		//set sprite origin to be in the centre of itself, so it rotates on the centre
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	}	
	sprite.rotate(0.5f);
}
