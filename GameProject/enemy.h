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

    // Add a CCollider member to your enemy class
    CCollider collider;

    // Implement the GetCollider method
    const CCollider& GetCollider() const {
        return collider;
    }

    int health = 50;

    // Decrease the enemy's health when hit by a projectile
    void DecreaseHealth(float damage);

    void Death() override;
    bool IsDefeated();


	void setApplication(CApplication* _application);

private:
	sf::Texture texture;
	CApplication* application;
	CWeapon weapon;
	float TimeUntilShoot;
};
