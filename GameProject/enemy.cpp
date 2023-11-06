#include "enemy.h"

void enemy::Load()
{
	texture.loadFromFile("Content/Textures/Enemies/enemyBlack1.png");
	setTexture(texture);
}

void enemy::Tick(float _deltaTime)
{
	sf::Vector2f EnemySpeed(0, 10);
	EnemySpeed *= 10.0f;
	sf::Vector2f ESpeed = EnemySpeed * _deltaTime;
	sprite.move(ESpeed);

	if (sprite.getPosition().y > 950)
	{
		setPosition(sf::Vector2f((rand() % 1200) + 100, 0));
	}
	

	//death when health is 0
	//if (health <= 0)
	//{
		//Destroy GameObject.Enemy;
	//}
	
}


//damage collision with projectile
// 
