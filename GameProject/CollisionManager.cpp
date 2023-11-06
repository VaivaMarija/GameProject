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
}

void CollisionManager::CheckForCollisions()
{	
	for (CGameObject* playerProjectile:PlayerProjectiles)
	{
		for (CGameObject* enemy:Enemies)
		{
			if (playerProjectile->GetCollider().IsColliding(enemy->GetCollider()))
			{
				enemy->Death();
			}
		}
	}
}
