#include "GameObject.h"
#include "Collider.h"  // Include your CCollider class

CGameObject::CGameObject()
{
    // Initialize your game object properties here.
}

void CGameObject::setTexture(const sf::Texture& _texture)
{
    sprite.setTexture(_texture);
    float radius = sprite.getLocalBounds().width / 2;
    collider = CCollider(radius, sprite.getPosition());
	sprite.setTexture(_texture);
}

void CGameObject::setType(ETexture type)
{
    textureType = type;
}

void CGameObject::drawTo(sf::RenderTarget& _target)
{
    collider.SetPosition(sprite.getPosition());
    _target.draw(sprite);
}

void CGameObject::Tick(float _deltaTime)
{
    // Implement your game logic here.
}

void CGameObject::setPosition(sf::Vector2f _position)
{
    sprite.setPosition(_position);

    // Update the collider's position when setting the object's position.
    collider.SetPosition(_position);
}

// Implement the GetCollider function as mentioned in previous responses.

const CCollider& CGameObject::GetCollider() const
{
    return collider;
}

CCollider& CGameObject::GetCollider()
{
    return collider;
}

sf::Vector2f CGameObject::GetPosition() const
{
    return sprite.getPosition();
}