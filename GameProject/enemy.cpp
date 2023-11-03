#include "enemy.h"
#include "Application.h"
//#include "ProjectilePool.h"

enemy::enemy(CProjectilePool& _projectilePool)
	: weapon(0.0f, _projectilePool)
{

}

void enemy::Load()
{
	texture.loadFromFile("Content/Textures/Enemies/enemyBlack1.png");
	setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
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
	
	TimeUntilShoot -= _deltaTime;
	 if(TimeUntilShoot <= 0)
	{
		int miliUntilShoot = (rand() % 500) + 500;
		TimeUntilShoot = static_cast<float>(miliUntilShoot) / 1000.0f;
        weapon.Fire(_deltaTime, application, sprite.getPosition(), 180.0f);
	}
	


	//death when health is 0
	//if (health <= 0)
	//{
		//Destroy GameObject.Enemy;
	//}
	//damage collision with projectile
	// 
}

void enemy::setApplication(CApplication* _application)
{
	application = _application;
}



