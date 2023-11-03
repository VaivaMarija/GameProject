#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "player.h"
#include "GameObject.h"

// ( get player face direction )
// ( move projectile from player direction )

// projectile types (for power-ups)


// weapon class, projectile pool (inside weapon?)

// Define the projectile types
enum class EProjectileType { Player, Enemy, PowerUp };

class CProjectile : public CGameObject
{
public:
    CProjectile();

    // Get the collider of the projectile
    const CCollider& GetCollider() const;

	void Tick(float _deltaTime) override;

	void setDirection(sf::Vector2f _direction);

	// function that returns projectile type?
	// with set speeds dmg etc, to then be used for enemies, powerups, etc.
private:
    // Projectile direction
    sf::Vector2f direction;

    // Projectile speed
    float speed;

    // Projectile damage
    float damage;

    // Add a collider for the projectile
    CCollider collider;

    // Projectile type
    EProjectileType projectileType;
};