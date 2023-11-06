#pragma once
#include "player.h"

class CHealthBar
{
public:
	CHealthBar(player* _playerObject);

	void renderTo(sf::RenderWindow& _window);

private:
	player* playerObject;

	sf::RectangleShape rectangleShape;
};

