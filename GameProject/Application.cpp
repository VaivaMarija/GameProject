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
	Player.Load();
	Player.setPlayerPos(sf::Vector2f(800, 450));

	Enemy.Load();
	Enemy.setEnemyPos(sf::Vector2f(100, 80));

	Enemy2.Load();
	Enemy2.setEnemyPos(sf::Vector2f(200, 160));

	while (_running)
	{
		while (_window.pollEvent(e))
		{
			ProcessWindowEvent(e);
		}

		_window.clear(sf::Color::Blue);

		Player.Tick();
		Enemy.Tick();
		Enemy2.Tick();
		// Todo: Add your game code!
		Player.renderTo(_window);
		Enemy.renderTo(_window);
		Enemy2.renderTo(_window);

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
