#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>
#include <vector>
#include "Enemy.h"

class CApplication
{
public:
	CApplication(const sf::String& windowTitle, unsigned int windowWidth, unsigned int windowHeight);
	~CApplication();

	void Run();
	
	std::vector<enemy>Enemies;

private:
	void ProcessWindowEvent(const sf::Event& e);
	void SpawnEnemy(sf::Vector2f atPosition);

	int x;
	int y;
	sf::RenderWindow _window;
	bool _running;
};