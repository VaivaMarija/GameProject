#pragma once
#include <SFML/System/Vector2.hpp>

class CApplication;

class CWeapon
{
public:
	CWeapon();
	CWeapon(float _fireRate);

	void Fire(float _deltaTime, CApplication* _application, sf::Vector2f _location, float _rotation);

private:
	float fireRate;
	float timeSinceLastShot;

};