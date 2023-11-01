#pragma once

#include <SFML/System/Vector2.hpp>

class CCollider
{
public:
    CCollider();
    CCollider(float radius, const sf::Vector2f& position);
    bool IsColliding(const CCollider& collider) const;

    const sf::Vector2f& GetPosition() const;
    float GetRadius() const;

    void SetPosition(const sf::Vector2f& position);

private:
    float radius;
    sf::Vector2f position;
};
