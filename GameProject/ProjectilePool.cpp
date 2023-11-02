#include "ProjectilePool.h"
#include "Application.h"

CProjectilePool::CProjectilePool(int poolSize)
{
	// initialize pool with a specified size
	projectiles.resize(poolSize);
	nextProjectile = 0;
}

void CProjectilePool::Load(CApplication* _application)
{
	for	(CProjectile& proj : projectiles)
	{
		proj.SetType(projectileType);
		proj.setPosition(sf::Vector2f(-10000, -10000)); // hides the projectiles away
		_application->addGameObject(&proj);
	}
}

CProjectile& CProjectilePool::getProjectile()
{
	CProjectile& projectile = projectiles[nextProjectile];
	nextProjectile++;
	if (nextProjectile == projectiles.size())
	{
		nextProjectile = 0;
	}
	return projectile;
}