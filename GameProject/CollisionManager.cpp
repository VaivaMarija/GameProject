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
		if (playerProjectile->isExploding)
		{
			continue;
		}
		for (CGameObject* enemy:Enemies)
		{
			if (playerProjectile->GetCollider().IsColliding(enemy->GetCollider()))
			{
				enemy->Death();
				playerObject->addScore(1);
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
		if (enemyProjectile->isExploding)
		{
			continue;
		}
		if (enemyProjectile->GetCollider().IsColliding(playerObject->GetCollider()))
		{
			enemyProjectile->SetKaboom(CTextureBank::enemyProjectileHitT);
			playerObject->decreaseHealth(2);
		}
	}
	// loop for asteroids + player
	for (CGameObject* asteroid : Asteroids)
	{
		if (asteroid->isExploding)
		{
			continue;
		}

		if (playerObject->GetCollider().IsColliding(asteroid->GetCollider()))
		{
			asteroid->Death();
			playerObject->decreaseHealth(1);
		}
	}
}

void CollisionManager::setPlayer(player* _playerObject)
{
	playerObject = _playerObject;
}