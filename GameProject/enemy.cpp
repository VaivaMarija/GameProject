#include "enemy.h"

void enemy::renderTo(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void enemy::setEnemyPos(sf::Vector2f newPos)
{
	sprite.setPosition(newPos);
}

void enemy::Load()
{
	texture.loadFromFile("Content/Textures/Enemies/enemyBlack1.png");
	sprite.setTexture(texture);
}

void enemy::Tick()
{
	sprite.move(0, 0.8f);
}
