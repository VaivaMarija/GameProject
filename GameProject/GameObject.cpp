#include "GameObject.h"


CGameObject::CGameObject()
{
}

void CGameObject::setTexture(const sf::Texture& _texture)
{
	sprite.setTexture(_texture);
}

void CGameObject::setType(ETexture type)
{
	textureType = type;
}

void CGameObject::drawTo(sf::RenderTarget& _target)
{
	_target.draw(sprite);
}

void CGameObject::Tick(float _deltaTime)
{
}

void CGameObject::setPosition(sf::Vector2f _position)
{
	sprite.setPosition(_position);
}