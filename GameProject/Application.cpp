#include "Application.h"
#include <SFML/Window/Event.hpp>

CApplication::CApplication(const sf::String& windowTitle, unsigned int windowWidth, unsigned int windowHeight)
	: _running(true)
{
	sf::VideoMode vm;
	vm.height = windowHeight;
	vm.width = windowWidth;
	_window.create(vm, windowTitle);
}

CApplication::~CApplication()
{
}

void CApplication::Run()
{
	sf::Event e;
	Enemies.reserve(10);
	//enemies
	SpawnEnemy(sf::Vector2f(200, 80));
	SpawnEnemy(sf::Vector2f(x, y));
	SpawnEnemy(sf::Vector2f(x, y));
	SpawnEnemy(sf::Vector2f(x, y));
	SpawnEnemy(sf::Vector2f(x, y));

	while (_running)
	{
		while (_window.pollEvent(e))
		{
			ProcessWindowEvent(e);
		}

		_window.clear(sf::Color::Blue);
		
		// Todo: Add your game code!
		
		for(enemy& e:Enemies)
		{
			e.Tick();
			e.renderTo(_window);
		}
		_window.display();
	}
}

void CApplication::ProcessWindowEvent(const sf::Event& e)
{
	if (e.type == sf::Event::Closed)
	{
		_running = false;
	}
}

//spawns enemy at "random" location
void CApplication::SpawnEnemy(sf::Vector2f atPosition)
{
	enemy& enemyRef = Enemies.emplace_back();
	enemyRef.Load();
	enemyRef.setEnemyPos(atPosition);
	x = (rand() % 1200) + 100;
	y = (rand() % 300) + 100;
}
