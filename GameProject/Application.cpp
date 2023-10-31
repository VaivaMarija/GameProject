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

	Enemy.Load();
	Enemy.setEnemyPos(sf::Vector2f(100, 80));

	Enemy2.Load();
	Enemy2.setEnemyPos(sf::Vector2f(200, 160));

	sf::Text pointsText;
	sf::Font font;
	if (!font.loadFromFile("Content/Fonts/TextFont.ttf"))
	{
		//error
	}
	//set font
	pointsText.setFont(font);

	while (_running)
	{
		sf::Time elapsed = clock.restart();
		float deltaTime = elapsed.asSeconds();
		while (_window.pollEvent(e))
		{
			ProcessWindowEvent(e);
		}

		_window.clear(sf::Color::Black);
	
		Player.Tick(deltaTime);
		Enemy.Tick();
		Enemy2.Tick();

		// Todo: Add your game code!
		Player.renderTo(_window);
		Enemy.renderTo(_window);
		Enemy2.renderTo(_window);
		
		//set string to display
		pointsText.setString(sf::String("HEALTH: ") + std::to_string(Player.getHealthPoints()));
		//set character size, pixels not points
		pointsText.setCharacterSize(24);
		//set colour
		pointsText.setFillColor(sf::Color::White);
		_window.draw(pointsText);
		
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
