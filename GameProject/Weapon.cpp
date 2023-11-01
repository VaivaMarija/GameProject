#include "Weapon.h"
#include "Application.h"
#include "Math.h"

CWeapon::CWeapon()
	: fireRate{0.2f}
{
}

CWeapon::CWeapon(float _fireRate)
{

}

void CWeapon::Fire(float _deltaTime, CApplication* _application, sf::Vector2f _location, float _rotation)
{
	if (timeSinceLastShot >= fireRate)
	{
		CProjectile* projectile = new CProjectile;
		projectile->setPosition(_location);

		sf::Vector2f direction;
		direction.x = sinf(math::DegToRad(_rotation));
		direction.y = cosf(math::DegToRad(_rotation)) * -1;
		projectile->setDirection(direction);

		timeSinceLastShot = 0.0f;

		_application->addGameObject(projectile);
	}
	timeSinceLastShot += _deltaTime;
}