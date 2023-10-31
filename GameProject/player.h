#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class player
{
public:
	void renderTo(sf::RenderWindow& window);
	void setPlayerPos(sf::Vector2f newPos);
	void Load();
	void Tick(float);
	void ReadKeyboardInput();

	bool wIsDown;
	bool aIsDown;
	bool dIsDown;
	bool LMBDown;
private:
	sf::Texture texture;
	sf::Sprite sprite;
};
