#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"

enum class EProjectileType {Player, Enemy, PowerUp};


// Base projectile class
class CProjectile : public CGameObject
{
public:
	CProjectile();

	// get projectile type
	EProjectileType projectileType;

	void SetType(EProjectileType _type);

	// function that returns projectile type? getType
	// with set speeds dmg etc, to then be used for enemies, powerups, etc.
	
	void Tick(float _deltaTime) override;

	void setDirection(sf::Vector2f _direction);

private:
	// projectile direction
	sf::Vector2f direction;

	// projectile speed
	float speed;
	// projectile damage
	float damage;

};
