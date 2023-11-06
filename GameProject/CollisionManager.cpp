#include "CollisionManager.h"

void CollisionManager::AddGameObject(CGameObject* gameObject)
{
	if (gameObject->GetCollisionType() == ECollisionType::PlayerProjectile)
	{
		PlayerProjectiles.push_back(gameObject);
	}
	if (gameObject->GetCollisionType() == ECollisionType::EnemyBody)
	{
		Enemies.push_back(gameObject);
	}
	if (gameObject->GetCollisionType() == ECollisionType::Asteroid)
	{
		Asteroids.push_back(gameObject);
	}
}
	if (gameObject->GetCollisionType() == ECollisionType::EnemyProjectile)
	{
		EnemyProjectiles.push_back(gameObject);
	}
}

void CollisionManager::CheckForCollisions()
{	
	// loop for player projectiles + enemies
	for (CGameObject* playerProjectile:PlayerProjectiles)
	{
		for (CGameObject* enemy:Enemies)
		{
			if (playerProjectile->GetCollider().IsColliding(enemy->GetCollider()))
			{
				enemy->Death();
			}
		}
		for (CGameObject* asteroid : Asteroids)
		{
			if (playerProjectile->GetCollider().IsColliding(asteroid->GetCollider()))
			{
				asteroid->Death();
			}
		}
	}

	// loop for enemy projectiles + player
	for (CGameObject* enemyProjectile : EnemyProjectiles)
	{
		if (enemyProjectile->GetCollider().IsColliding(playerObject->GetCollider()))
		{
			enemyProjectile->setPosition(sf::Vector2f(10000.0f, 10000.0f));
			playerObject->decreaseHealth(5);
		}
	}
}

void CollisionManager::setPlayer(player* _playerObject)
{
	playerObject = _playerObject;
}