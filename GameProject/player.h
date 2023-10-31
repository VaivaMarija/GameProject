#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "player.h"
#include "Projectile.h"
#include <vector>

class player
{
public:
	void renderTo(sf::RenderWindow& window);
	void setPlayerPos(sf::Vector2f newPos);
	void Load();
	void Tick();
	void ReadKeyboardInput();

	sf::Vector2f getPlayerPosition() const; // move to the thing later

	bool wIsDown;
	bool aIsDown;
	bool dIsDown;
	bool LMBDown;
	bool spaceIsDown;
private:
	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<CProjectile> magazine;

	CProjectile* Projectile = nullptr;
};
