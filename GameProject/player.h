#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Projectile.h"

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

	bool wIsDown;
	bool aIsDown;
	bool dIsDown;
	bool LMBDown;
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float healthPoints;
};
