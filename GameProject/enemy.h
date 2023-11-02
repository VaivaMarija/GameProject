#pragma once
#include "SFML/Graphics.hpp"
#include "Math.h"
#include <iostream>
#include "Collider.h"  // Include the Collider class

#include "GameObject.h"
class enemy : public CGameObject
{
public:

	
	void Load();
	void Tick(float _deltaTime) override;

    // Add a CCollider member to your enemy class
    CCollider collider;

    // Implement the GetCollider method
    const CCollider& GetCollider() const {
        return collider;
    }

	int health = 50;
	//void Death();

private:
	sf::Texture texture;
	
};
