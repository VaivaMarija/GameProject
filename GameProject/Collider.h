#pragma once

#include <SFML/System/Vector2.hpp>

class CCollider
{
public:
	bool IsColliding(const CCollider& collider) const;

protected:

private:
	float radius;
	sf::Vector2f position;
};