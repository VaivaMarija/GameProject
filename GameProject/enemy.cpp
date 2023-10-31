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
	sprite.move(0, 0.5);

	if (sprite.getPosition().y > 950)
	{
		setEnemyPos(sf::Vector2f(sprite.getPosition().x, 0));
	}

	//death when health is 0
	//if (health <= 0)
	//{
		//Destroy GameObject.Enemy;
	//}
	sprite.move(0, 0.8f);
}




//health 
//
//damage collision with projectile
// 
