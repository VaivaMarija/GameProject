#pragma once

class CWeapon
{
public:
	CWeapon(float _fireRate, float _maxAmmo);

	void Fire(float _deltaTime);

private:
	float fireRate;
	float reloadTime;

	float currentAmmo;
	float maxAmmo;

};