#pragma once
#include <SFML/System/Vector2.hpp>
#include "ProjectilePool.h"
#include "Projectile.h"

class CApplication;

class CWeapon
{
public:
	CWeapon(CProjectilePool& _projectilePool);
	CWeapon(float _fireRate, CProjectilePool& _projectilePool);

	void Fire(float _deltaTime, CApplication* _application, sf::Vector2f _location, float _rotation);

private:
	float fireRate;
	float timeSinceLastShot;

	CProjectilePool* projectilePool;
};