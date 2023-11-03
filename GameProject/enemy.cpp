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

    // For now, let's remove the enemy by setting its position off-screen.
    setPosition(sf::Vector2f(-1000, -1000)); // Move the enemy out of the visible area.
}

