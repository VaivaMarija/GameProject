#include "Collider.h"

CCollider::CCollider()
    : radius(0.0f), position(sf::Vector2f(0.0f, 0.0f))
{
}

CCollider::CCollider(float radius, const sf::Vector2f& position)
    : radius(radius), position(position)
{
}

bool CCollider::IsColliding(const CCollider& collider) const
{
    // Calculate the distance between the centers of the two colliders.
    sf::Vector2f distance = position - collider.GetPosition();
    float totalRadius = radius + collider.GetRadius();

    // Check if the distance is less than or equal to the sum of the radii.
    return (distance.x * distance.x + distance.y * distance.y) <= (totalRadius * totalRadius);
}

const sf::Vector2f& CCollider::GetPosition() const
{
    return position;
}

float CCollider::GetRadius() const
{
    return radius;
}

void CCollider::SetPosition(const sf::Vector2f& newPosition)
{
    position = newPosition;
}
