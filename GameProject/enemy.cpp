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

void enemy::Tick(float _deltaTime)
{
	sf::Vector2f EnemySpeed(0, 10);
	EnemySpeed *= 15.0f;
	sf::Vector2f ESpeed = EnemySpeed * _deltaTime;
	sprite.move(ESpeed);

	if (sprite.getPosition().y > 950)
	{
		setEnemyPos(sf::Vector2f(sprite.getPosition().x, 0));
	}

	//death when health is 0
	//if (health <= 0)
	//{
		//Destroy GameObject.Enemy;
	//}
}




//health 
//
//damage collision with projectile
// 
