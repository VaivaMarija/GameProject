#include "Projectile.h"
#include "TextureBank.h"
#include "Math.h"

// Base Projectile
CProjectile::CProjectile()
	:	speed{1000.0f},
		direction{0, -1.0}
{
	setTexture(CTextureBank::playerProjectileT);
}

void CProjectile::SetType(EProjectileType _type)
{
	projectileType = _type;
}

void CProjectile::Tick(float _deltaTime)
{
	sprite.move(direction * speed * _deltaTime);
}

void CProjectile::setDirection(sf::Vector2f _direction)
{
	float rotation = atan2f( - _direction.x, _direction.y); // rotation in radians
	sprite.setRotation(math::RadToDeg(rotation));
	direction = _direction;
}