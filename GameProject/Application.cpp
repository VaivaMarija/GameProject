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
	//Projectile.SetType(Player);
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
	Enemies.reserve(10);
	//enemies
	SpawnEnemy(sf::Vector2f(200, 80));
	SpawnEnemy(sf::Vector2f(x, y));
	SpawnEnemy(sf::Vector2f(x, y));
	SpawnEnemy(sf::Vector2f(x, y));
	SpawnEnemy(sf::Vector2f(x, y));

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

		// Todo: Add your game code!
		Player.renderTo(_window);
		

		
		Projectile.Tick();
		// drawing a projectile to window
		_window.draw(Projectile.sprite);


		
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
