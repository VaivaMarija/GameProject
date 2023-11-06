#pragma once
#include "player.h"

class CHealthBar
{
public:
	CHealthBar(player* _playerObject);

	void renderTo(sf::RenderWindow& _window);
	void Tick(float _deltaTime);

private:
	player* playerObject;

	sf::RectangleShape rectangleShape;
};

