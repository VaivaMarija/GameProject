#include "Application.h"
#include <SFML/Window/Event.hpp>

CApplication::CApplication(const sf::String& windowTitle, unsigned int windowWidth, unsigned int windowHeight)
	: _running(true)
{
	sf::VideoMode vm;
	vm.height = windowHeight;
	vm.width = windowWidth;
	_window.create(vm, windowTitle);

	// set projectile type
	Projectile.SetType(Player);
	// spawning a projectile at the center of the window ( move to player later)
	Projectile.SpawnProjectile({ static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2 });
}

CApplication::~CApplication()
{
}

void CApplication::Run()
{
	sf::Event e;

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
		Enemy.Tick();
		Enemy2.Tick();

		// Todo: Add your game code!
		Enemy.renderTo(_window);
		Enemy2.renderTo(_window);

		
		Projectile.Tick();
		// drawing a projectile to window
		_window.draw(Projectile.sprite);


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
