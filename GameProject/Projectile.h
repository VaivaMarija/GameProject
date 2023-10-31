#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "GameObject.h"

// move projectile to a direction	-Done(ish)
// ( get player face direction )
// ( move projectile from player direction )

// projectile types (for power-ups)


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

private:
	// projectile direction
	sf::Vector2f direction;

	// projectile speed
	float speed;
	// projectile damage
	float damage;

};
