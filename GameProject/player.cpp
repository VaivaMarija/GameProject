#include "player.h"
#include "Math.h"
#include "Application.h"

void player::renderTo(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void player::setPlayerPos(sf::Vector2f newPos)
{
	sprite.setPosition(newPos);
}

void player::Load() 
{
	//load texture
	texture.loadFromFile("Content/Textures/Player/playerShip1_blue.png");
	//add texture to sprite
	sprite.setTexture(texture);
	//set sprite origin to be in the centre of itself, so it rotates on the centre
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	
	setHealthPoints(3);
}

void player::ReadKeyboardInput()
{
	//use the sf::Keyboard to check for keyboard input
	// sf::Keyboard::Key enum containing all keys
	wIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
	aIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
	dIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);

	spaceIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);

	//use sf::Mouse to check for mouse input
	// sf::Mouse:: enum containing all buttons
	LMBDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

float player::getHealthPoints()
{
	return healthPoints;
}

void player::setHealthPoints(float _newHealthPoints)
{
	healthPoints = _newHealthPoints;
}

bool player::checkForDeath()
{
	return healthPoints = 0;
}

void player::Tick(float _deltaTime)
{
	ReadKeyboardInput();
	float RotAsRad = math::DegToRad(sprite.getRotation());
	if(wIsDown)
	{
		//move player forward
		//create vector2
		sf::Vector2f movement(sin(RotAsRad), cos(RotAsRad) * -1);
		movement *= 180.0f;
		sf::Vector2f scaledMovement = movement * _deltaTime;
		if (true)
		{
			sprite.move(scaledMovement);
		}
	}
	if(aIsDown)
	{
		//rotate player left
		sprite.rotate(-120.0f * _deltaTime);
	}
	if (dIsDown)
	{
		//rotate player left
		sprite.rotate(120.0f * _deltaTime);
	}
	if (spaceIsDown)
	{
		//shoot projectile
		CProjectile* projectile = new CProjectile;
		projectile->setPosition(getPlayerPosition());
		application->addGameObject(projectile);
	}

}

sf::Vector2f player::getPlayerPosition() const
{
	return sprite.getPosition();
}

/*
// get player rotation ?
sf::Vector2f player::getPLayerRotation()
{
	return sprite.getRotation();
}
*/


void player::setApplication(CApplication* _application)
{
	application = _application;
}