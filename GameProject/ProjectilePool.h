#pragma once
#include "Projectile.h"

class CApplication;

class CProjectilePool
{
public:
	CProjectilePool(int poolSize);

	EProjectileType projectileType;

	void Load(CApplication* _application);

	// get next available projectile
	CProjectile& getProjectile();

private:

	// Projectile vector
	std::vector<CProjectile> projectiles;

	int nextProjectile;

};