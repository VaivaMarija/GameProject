#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Collider.h"

enum class ETexture { Player, Enemy, Asteroid };

enum class ECollisionType { PlayerBody, EnemyBody, Asteroid, PlayerProjectile, EnemyProjectile };


class CGameObject
{
public:
    CGameObject();

    ETexture textureType;
    
    void setType(ETexture type);

    void setTexture(const sf::Texture& _texture);

    void drawTo(sf::RenderTarget& _target);

    void setPosition(sf::Vector2f _position);

    virtual void Tick(float _deltaTime);

    // Add this function to retrieve the collider
    const CCollider& GetCollider() const;
    CCollider& GetCollider();

    sf::Vector2f GetPosition() const;

	// function that destroys the objects once they're out of screen bounds.

protected:
    sf::Sprite sprite;
    CCollider collider;  // Add a collider member
    ECollisionType collisionType;
private:
};
