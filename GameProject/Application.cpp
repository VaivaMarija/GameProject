#include "Application.h"
#include <SFML/Window/Event.hpp>

CApplication::CApplication(const sf::String& windowTitle, unsigned int windowWidth, unsigned int windowHeight)
	: _running(true)
{
	sf::VideoMode vm;
	vm.height = windowHeight;
	vm.width = windowWidth;
	_window.create(vm, windowTitle);

	// spawning a projectile at the center of the window ( move to player later)
	Projectile.SpawnProjectile({ static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2 });
}

CApplication::~CApplication()
{
}

void CApplication::Run()
{
	sf::Event e;

	while (_running)
	{
		while (_window.pollEvent(e))
		{
			ProcessWindowEvent(e);
		}

		_window.clear(sf::Color::Blue);

		// Todo: Add your game code!
		

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
