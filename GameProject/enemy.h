#pragma once
#include "SFML/Graphics.hpp"
#include "Math.h"
#include <iostream>

#include "GameObject.h"
class enemy : public CGameObject
{
public:

	void Load();
	void Tick(float _deltaTime) override;


	int health = 50;
	//void Death();

private:
	sf::Texture texture;
	
};

