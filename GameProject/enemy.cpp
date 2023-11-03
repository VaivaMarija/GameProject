#include "enemy.h"
#include "Application.h"
#include "TextureBank.h"
//#include "ProjectilePool.h"

enemy::enemy(CProjectilePool& _projectilePool)
	: weapon(0.0f, _projectilePool)
{

}

void enemy::Load()
{
	setTexture(CTextureBank::enemyT);
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
	if (TimeUntilShoot <= 0)
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

void enemy::DecreaseHealth(float damage)
{
	health -= damage;

	// Check if health is less than or equal to 0 and handle enemy death
	if (health <= 0)
	{
		Death();
	}
}

bool enemy::IsDefeated()
{
	return false;
}

void enemy::Death()
{
	// Handle enemy death logic here
	std::cout << "Enemy has been defeated!" << std::endl;

	// You can add further logic here, such as playing a death animation, awarding points to the player, or removing the enemy from the game.
}


