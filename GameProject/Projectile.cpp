#include "Projectile.h"


// Base Projectile
CProjectile::CProjectile()
	: speed{1.0f},
	direction{1, 0}
{
	SetTexture();
}


// Projectile texture
void CProjectile::SetTexture()
{
	// Load from file with the relative path of the image file
	texture.loadFromFile("Content/Textures/Lasers/laserGreen.png");

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











// Enemy Projectile