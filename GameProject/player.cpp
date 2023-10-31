#include "player.h"

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
	texture.loadFromFile("Content/Textures/Player/playerShip1_blue.png");
	sprite.setTexture(texture);
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

void player::Tick()
{
	ReadKeyboardInput();
	if(wIsDown)
	{
		//move player forward
		sprite.move(0, 0.1);
	}
	if(aIsDown)
	{
		//rotate player left
		sprite.rotate(0.1f);
	}
	if (dIsDown)
	{
		//rotate player left
		sprite.rotate(0.1f);
	}
	if (spaceIsDown)
	{
		//shoot projectile
		//Projectile.sprite.move(0, -1.0f);
	}

}

sf::Vector2f player::getPlayerPosition() const
{
	return sprite.getPosition();
}