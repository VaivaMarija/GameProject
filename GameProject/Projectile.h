#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "player.h"
#include "GameObject.h"

// ( get player face direction )
// ( move projectile from player direction )

// projectile types (for power-ups)


// weapon class, projectile pool (inside weapon?)

enum class EProjectileType {Player, Enemy, PowerUp};


// Base projectile class
class CProjectile : public CGameObject
{
public:
	CProjectile();

	// get projectile type
	EProjectileType projectileType;

	void SetType(EProjectileType _type);

	void Tick(float _deltaTime) override;

	void setDirection(sf::Vector2f _direction);

	// function that returns projectile type?
	// with set speeds dmg etc, to then be used for enemies, powerups, etc.
private:
	// projectile direction
	sf::Vector2f direction;

	// projectile speed
	float speed;
	// projectile damage
	float damage;

	//player Player;

};
