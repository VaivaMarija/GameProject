#pragma once
#include "SFML/Graphics.hpp"
#include "Projectile.h"
#include "Weapon.h"
#include <vector>
#include "Collider.h"  // Include the Collider class
#include <SFML/Graphics/Rect.hpp>

class CApplication;

class player
{
public:
	void renderTo(sf::RenderWindow& window);
	void setPlayerPos(sf::Vector2f newPos);
	void Load(sf::Vector2u _windowSize);
	void Tick(float);
	void ReadKeyboardInput();
	int getHealthPoints();
	void decreaseHealth();
	void resetHealth();
	bool checkForDeath();
	int getScore();
	void addScore(int _scoreToAdd);
	void resetScore();

    sf::Vector2f getPlayerPosition() const; // move to the thing later

	bool wIsDown;
	bool aIsDown;
	bool dIsDown;
	bool LMBDown;
	bool spaceIsDown;
	bool debugIsDown;

    void setApplication(CApplication* _application);

    // Add a CCollider member to your player class
    CCollider collider;

    // Implement the GetCollider method
    const CCollider& GetCollider() const {
        return collider;
    }

private:
	sf::Texture texture;
	sf::Sprite sprite;
	int healthPoints;
	int score;

	sf::FloatRect windowRectangle;
	CApplication* application;

	CWeapon weapon;
};
