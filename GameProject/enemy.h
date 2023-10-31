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

private:
	sf::Texture texture;
	sf::Sprite sprite;
};

