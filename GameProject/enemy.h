#pragma once
#include "SFML/Graphics.hpp"

#include <iostream>

class enemy
{
public:

	void renderTo(sf::RenderWindow& window);
	void setEnemyPos(sf::Vector2f newPos);	
	void Load();
	void Tick();

	int health = 50;
	void Death();

private:
	sf::Texture texture;
	sf::Sprite sprite;
};

