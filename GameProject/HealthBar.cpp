#include "HealthBar.h"

CHealthBar::CHealthBar(player* _playerObject)
{
	playerObject = _playerObject;
}

void CHealthBar::renderTo(sf::RenderWindow& _window)
{
	rectangleShape.setSize(sf::Vector2f(50.f, 10.f));
	rectangleShape.setPosition(5, 35);

	for (int i = 0; i <= playerObject->getHealthPoints(); i++)
	{
		_window.draw(rectangleShape);
		rectangleShape.move(55, 0);
	}
}

void CHealthBar::Tick(float _deltaTime)
{

}
