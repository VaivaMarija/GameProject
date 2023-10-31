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
	sf::Clock clock;
	

	sf::Event e;
	Player.Load();
	Player.setPlayerPos(sf::Vector2f(800, 450));

	Enemy.Load();
	Enemy.setEnemyPos(sf::Vector2f(100, 80));

	Enemy2.Load();
	Enemy2.setEnemyPos(sf::Vector2f(200, 160));

	while (_running)
	{
		sf::Time elapsed = clock.restart();
		float deltaTime = elapsed.asSeconds();
		while (_window.pollEvent(e))
		{
			ProcessWindowEvent(e);
		}

		_window.clear(sf::Color::Blue);
	
		Player.Tick(deltaTime);
		Enemy.Tick();
		Enemy2.Tick();

		// Todo: Add your game code!
		Player.renderTo(_window);
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
