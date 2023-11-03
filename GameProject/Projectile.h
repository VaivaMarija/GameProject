#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"

enum class EProjectileType {Player, Enemy, PowerUp};


class CProjectile : public CGameObject
{
public:
	CProjectile();

	// get projectile type
	EProjectileType projectileType;

	void SetType(EProjectileType _type);
	
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
