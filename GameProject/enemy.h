#pragma once
#include "SFML/Graphics.hpp"
#include "Math.h"
#include <iostream>
#include "Weapon.h"
#include "GameObject.h"

class CApplication;
//class CProjectilePool;

class enemy : public CGameObject
{
public:
	enemy(CProjectilePool& _projectilePool);

	void Load();
	void Tick(float _deltaTime) override;


	int health = 50;
	//void Death();


	void setApplication(CApplication* _application);

private:
	sf::Texture texture;
	CApplication* application;
	CWeapon weapon;
	float TimeUntilShoot;
};

