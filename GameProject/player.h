#pragma once
#include "SFML/Graphics.hpp"
#include "Projectile.h"
#include <vector>

class CApplication;

class player
{
public:
	void renderTo(sf::RenderWindow& window);
	void setPlayerPos(sf::Vector2f newPos);
	void Load();
	void Tick(float);
	void ReadKeyboardInput();
	float getHealthPoints();
	void setHealthPoints(float _newHealthPoints);
	bool checkForDeath();

	sf::Vector2f getPlayerPosition() const; // move to the thing later

	bool wIsDown;
	bool aIsDown;
	bool dIsDown;
	bool LMBDown;
	bool spaceIsDown;

	void setApplication(CApplication* _application);

private:
	sf::Texture texture;
	sf::Sprite sprite;
	float healthPoints;

	std::vector<CProjectile> magazine;

	CApplication* application;
};
