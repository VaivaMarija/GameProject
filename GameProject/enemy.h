#pragma once
#include "SFML/Graphics.hpp"
#include "Math.h"
#include <iostream>

class enemy
{
public:

	void renderTo(sf::RenderWindow& window);
	void setEnemyPos(sf::Vector2f newPos);	
	void Load();
	void Tick(float _deltaTime);


	int health = 50;
	void Death();

private:
	sf::Texture  texture;
	sf::Sprite sprite;
};

