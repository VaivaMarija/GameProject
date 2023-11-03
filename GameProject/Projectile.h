#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"

enum class EProjectileType {Player, Enemy, PowerUp};


class CProjectile : public CGameObject
{
public:
    CProjectile();

    // Get the collider of the projectile
    const CCollider& GetCollider() const;

	void SetType(EProjectileType _type);
	
	void Tick(float _deltaTime) override;

	void setDirection(sf::Vector2f _direction);

private:
    EProjectileType projectileType;

    // Projectile direction
    sf::Vector2f direction;

    // Projectile speed
    float speed;

    // Projectile damage
    float damage;

};
