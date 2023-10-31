#include "Projectile.h"


// Base Projectile
CProjectile::CProjectile()
	:	speed{1.0f},
		direction{1, 0}
{
	SetTexture();
}

void CProjectile::SetType(EProjectileType Type)
{
	projectileType = Type;
}

// Projectile texture
void CProjectile::SetTexture()
{
	if (projectileType == Player)
	{
		// Load from file with the relative path of the image file
		texture.loadFromFile("Content/Textures/Lasers/laserGreen.png");
	}
	else if (projectileType == Enemy)
	{
		// Load from file with the relative path of the image file
		texture.loadFromFile("Content/Textures/Lasers/laserRed.png");
	}
	else
	{
		// Load from file with the relative path of the image file
		texture.loadFromFile("Content/Textures/Lasers/laserBlue.png");
	}

	// Set texture
	sprite.setTexture(texture);
}

void CProjectile::SpawnProjectile(sf::Vector2f location)
{
	sprite.setPosition(location); // will change to spawn from player location

}


void CProjectile::Tick()
{
	sprite.move(direction * speed);
}

