#include "player.h"
#include "Math.h"
#include "Application.h"
#include "TextureBank.h"
#include "SoundBank.h"

player::player(CProjectilePool& _projectilePool)
	:	weapon(0.2f, _projectilePool)
{
	collisionType = ECollisionType::PlayerBody;
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

	//set texture to sprite
	sprite.setTexture(CTextureBank::playerT, true);
	//set sprite origin to be in the centre of itself, so it rotates on the centre
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	collider = CCollider(sprite.getGlobalBounds().width / 2, getPlayerPosition());
	resetHealth();
}

void player::ReadKeyboardInput()
{
	//use the sf::Keyboard to check for keyboard input
	// sf::Keyboard::Key enum containing all keys
	wIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
	aIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
	dIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
	qIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q);
	debugIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O);

	spaceIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);

	restartIsDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R);

	//use sf::Mouse to check for mouse input
	// sf::Mouse:: enum containing all buttons
	LMBDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

int player::getHealthPoints()
{
	return healthPoints;
}

void player::decreaseHealth(int _amount)
{
	healthPoints = healthPoints - _amount;
	CSoundBank::GetInstance().enemyHitS.play();
	CApplication::setIsDead(checkForDeath());
}

void player::resetHealth()
{
	healthPoints = 10;
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
		sprite.rotate(-150.0f * _deltaTime);
	}
	if (dIsDown)
	{
		//rotate player left
		sprite.rotate(150.0f * _deltaTime);
	}
	if (qIsDown)
	{
		//quit game
		application->setQuitting(true);
	}
	if (spaceIsDown)
	{
		//shoot projectile
		weapon.Fire(_deltaTime, application, getPlayerPosition(), sprite.getRotation());
	}
	if (debugIsDown)
	{
		decreaseHealth(30);
	}
	if (restartIsDown)
	{
		application->setRestart(true);
	}

	collider.SetPosition(sprite.getPosition());
}

float player::GetProjectileDamage() const
{
	return -10;
}


sf::Vector2f player::getPlayerPosition() const
{
	return sprite.getPosition();
}


void player::setApplication(CApplication* _application)
{
	application = _application;
}
