#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

// create projectile to spawn
// spawn projectile at (player - from player class) location
// move projectile to a direction
// ( get player face direction )
// ( move projectile from player direction )

// projectile types (for power-ups)

// how about just a bunch of projectile types in one class
// and then player/enemy/power-up/etc will select which one to spawn when?



// Base projectile class
class CProjectile
{
public:
	CProjectile();

	// Spawn at location
	void SpawnProjectile(sf::Vector2f location);

	// get projectile

	// Projectile sprite
	sf::Sprite sprite;
	void Tick(/*float speed, sf::Vector2f direction*/);

protected:
	// Projectile texture
	sf::Texture texture;

private:
	// Sets the texture for projectile sprite
	void SetTexture();

	// projectile direction
	sf::Vector2f direction;

	// projectile speed
	float speed;




	// projectile damage
	float damage;

};


















/*
// Child Projectile class for Enemies
class CEnemyProjectile : public CProjectile
{
public:
	CEnemyProjectile();

	// get projectile

protected:

private:
	// Projectile texture
	void ProjectileSprite();
};
*/

