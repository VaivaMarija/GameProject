#include "Weapon.h"
#include "Application.h"
#include "Math.h"

CWeapon::CWeapon(CProjectilePool& _projectilePool)
	: fireRate{0.2f}
{
	projectilePool = &_projectilePool;
}

CWeapon::CWeapon(float _fireRate, CProjectilePool& _projectilePool)
{
	fireRate = _fireRate;
	projectilePool = &_projectilePool;
}

void CWeapon::Fire(float _deltaTime, CApplication* _application, sf::Vector2f _location, float _rotation)
{
	if (timeSinceLastShot >= fireRate)
	{
		CProjectile& projectile = projectilePool->getProjectile();
		projectile.setPosition(_location);

		sf::Vector2f direction;
		direction.x = sinf(math::DegToRad(_rotation));
		direction.y = cosf(math::DegToRad(_rotation)) * -1;
		projectile.setDirection(direction);

		timeSinceLastShot = 0.0f;
	}
	timeSinceLastShot += _deltaTime;
}