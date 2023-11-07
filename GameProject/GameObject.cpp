#include "GameObject.h"
#include "Collider.h"  // Include your CCollider class


CGameObject::CGameObject()
{
    // Initialize your game object properties here.
    isExploding = false;
}

void CGameObject::setTexture(const sf::Texture& _texture)
{
    sprite.setTexture(_texture, true);
    float radius = sprite.getLocalBounds().width / 2;
    collider = CCollider(radius, sprite.getPosition());
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
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

void CGameObject::DoTick(float _deltaTime)
{
    float kaboomTime = kaboomTimer.getElapsedTime().asSeconds();
    if (kaboomTime >= duration && isExploding)
    {
        isExploding = false;
        sprite.setScale(sf::Vector2f(1, 1));
        Respawn();
    }
    else if(isExploding)
    {        
        int MaxScale = rand() % 4 + 1;
        float kaboomFactor = kaboomTime / duration;
        sprite.setScale(sf::Vector2f(kaboomFactor * MaxScale,  kaboomFactor * MaxScale));
    }
    if (!isExploding)
    {
        Tick(_deltaTime);
    }
}

void CGameObject::setPosition(sf::Vector2f _position)
{
    sprite.setPosition(_position);

    // Update the collider's position when setting the object's position.
    collider.SetPosition(_position);
}

void CGameObject::Death()
{
}

void CGameObject::Respawn()
{
}

ECollisionType CGameObject::GetCollisionType() const
{
    return collisionType;
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

void CGameObject::SetKaboom(const sf::Texture& explosionT)
{     
    if (isExploding)
    {
        return;
    }
    isExploding = true;
    kaboomTimer.restart();
    setTexture(explosionT);  
}
