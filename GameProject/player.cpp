#include "player.h"
#include "Math.h"
#include "Application.h"

player::player(CProjectilePool& _projectilePool)
	:	weapon(0.2f, _projectilePool)
{
}

void player::renderTo(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void player::setPlayerPos(sf::Vector2f newPos)
{
	sprite.setPosition(newPos);
}

void player::Load(sf::Vector2u _windowSize) 
{
	windowRectangle.width = _windowSize.x;
	windowRectangle.height = _windowSize.y;
	//load texture
	texture.loadFromFile("Content/Textures/Player/playerShip1_blue.png");
	//add texture to sprite
	sprite.setTexture(texture);
	//set sprite origin to be in the centre of itself, so it rotates on the centre
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	
	healthPoints = 30;
}

void player::ReadKeyboardInput()
{
	//use the sf::Keyboard to check for keyboard input
	// sf::Keyboard::Key enum containing all keys
	wIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
	aIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
	dIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
	debugIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O);

	spaceIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);

	//use sf::Mouse to check for mouse input
	// sf::Mouse:: enum containing all buttons
	LMBDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

int player::getHealthPoints()
{
	return healthPoints;
}

void player::decreaseHealth()
{
	healthPoints = healthPoints - 10;
	CApplication::setIsDead(checkForDeath());
}

void player::resetHealth()
{
	healthPoints = 30;
}

bool player::checkForDeath()
{
	return healthPoints <= 0;
}

int player::getScore()
{
	return score;
}

void player::addScore(int _scoreToAdd)
{
	score = score + 10;
}

void player::resetScore()
{
	score = 0;
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
		//if the windowrectangle contains the next position of the player, we allow movement, if not, player is exiting the play area so we stop them
		if (windowRectangle.contains(sprite.getPosition() + scaledMovement))
		{
			sprite.move(scaledMovement);
		}
	}
	if(aIsDown)
	{
		//rotate player left
		sprite.rotate(-150.0 * _deltaTime);
	}
	if (dIsDown)
	{
		//rotate player left
		sprite.rotate(150.0f * _deltaTime);
	}
	if (spaceIsDown)
	{
		//shoot projectile
		weapon.Fire(_deltaTime, application, getPlayerPosition(), sprite.getRotation());
	}
	if (debugIsDown)
	{
		decreaseHealth();
	}

}

sf::Vector2f player::getPlayerPosition() const
{
	return sprite.getPosition();
}


void player::setApplication(CApplication* _application)
{
	application = _application;
}
