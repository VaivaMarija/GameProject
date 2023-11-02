#pragma once

#include "SFML/Graphics.hpp"
#include "Math.h"
#include <iostream>

#include "GameObject.h"

class Asteroids :  public CGameObject
{
public:

	
	void Load();
	void Tick(float _deltaTime) override;


	int health = 10;


private:
	sf::Texture texture;
	
};

