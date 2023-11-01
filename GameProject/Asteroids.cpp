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

		//sprite.setTexture(TextureBank::)
	}	
	sprite.rotate(0.5f);
}
