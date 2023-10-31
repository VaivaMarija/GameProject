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
	int getHealthPoints();
	void decreaseHealth();
	void resetHealth();
	bool checkForDeath();
	int getScore();
	void addScore(int _scoreToAdd);
	void resetScore();

	bool wIsDown;
	bool aIsDown;
	bool dIsDown;
	bool LMBDown;
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int healthPoints;
	int score;
};
