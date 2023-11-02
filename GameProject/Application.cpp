#include "Application.h"
#include "TextureBank.h"
#include <SFML/Window/Event.hpp>

bool CApplication::isDead = false;

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

void CApplication::setIsDead(bool _isTrue)
{
	isDead = _isTrue;

}

bool CApplication::getIsDead()
{
	return isDead;
}

void CApplication::Run()
{
	sf::Clock clock;
	sf::Clock deathTimer;

	sf::Event e;

	Player.setApplication(this);
	Player.Load(_window.getSize());
	Player.setPlayerPos(sf::Vector2f(800, 450));

	//enemies
	Enemies.reserve(10);
	SpawnEnemy(sf::Vector2f(200, 80));
	SpawnEnemy(sf::Vector2f(x, y));
	SpawnEnemy(sf::Vector2f(x, y));
	SpawnEnemy(sf::Vector2f(x, y));
	SpawnEnemy(sf::Vector2f(x, y));

	//Asteroids
	asteroids.reserve(8);
	SpawnAsteroids(sf::Vector2f(x, y));
	SpawnAsteroids(sf::Vector2f(x, y));
	SpawnAsteroids(sf::Vector2f(x, y));
	SpawnAsteroids(sf::Vector2f(x, y));

	// projectile
	CTextureBank::loadAllTextures();
	CProjectile projectile;
	projectile.setPosition(Player.getPlayerPosition());
	addGameObject(&projectile);

	sf::Text pointsText;
	sf::Font font;
	if (!font.loadFromFile("Content/Fonts/TextFont.ttf"))
	{
		//error
	}
	//set font
	pointsText.setFont(font);
	//set character size, pixels not points
	pointsText.setCharacterSize(24);
	//set colour
	pointsText.setFillColor(sf::Color::White);
	pointsText.setPosition(5.f,0);

	sf::Text healthText;
	healthText.setFont(font);
	healthText.setCharacterSize(24);
	healthText.setFillColor(sf::Color::White);
	healthText.setPosition(0, 25);


	sf::Text deathText;
	deathText.setFont(font);
	deathText.setCharacterSize(240);
	deathText.setOrigin(deathText.getGlobalBounds().width / 2, deathText.getGlobalBounds().height / 2);
	deathText.setPosition(300, 250);
	deathText.setFillColor(sf::Color::White);
	deathText.setString(sf::String("YOU DIED"));

	sf::RectangleShape healthbar1(sf::Vector2f(50.f, 10.f));
	healthbar1.setPosition(5,35);

	sf::RectangleShape healthbar2(sf::Vector2f(50.f, 10.f));
	healthbar2.setPosition(65, 35);

	sf::RectangleShape healthbar3(sf::Vector2f(50.f, 10.f));
	healthbar3.setPosition(125, 35);

	while (_running)
	{
		const bool wasDead = isDead;

		// deltaTime
		sf::Time elapsed = clock.restart();
		float deltaTime = elapsed.asSeconds();
		while (_window.pollEvent(e))
		{
			ProcessWindowEvent(e);
		}

		_window.clear(sf::Color::Black);

		Player.Tick(deltaTime);
		Player.renderTo(_window);
		// Todo: Add your game code!

		// Todo: Add your game code!
		Player.renderTo(_window);


		//set string to display
		pointsText.setString(sf::String("POINTS: ") + std::to_string(Player.getScore()));

		//show and hide health bars based on player's health
		switch (Player.getHealthPoints())
		{
		case 30:
			healthbar1.setFillColor(sf::Color::White);
			healthbar2.setFillColor(sf::Color::White);
			healthbar3.setFillColor(sf::Color::White);
			break;
		case 20:
			healthbar1.setFillColor(sf::Color::White);
			healthbar2.setFillColor(sf::Color::White);
			healthbar3.setFillColor(sf::Color::Transparent);
			break;
		case 10:
			healthbar1.setFillColor(sf::Color::White);
			healthbar2.setFillColor(sf::Color::Transparent);
			healthbar3.setFillColor(sf::Color::Transparent);
			break;
		default:
			healthbar1.setFillColor(sf::Color::Transparent);
			healthbar2.setFillColor(sf::Color::Transparent);
			healthbar3.setFillColor(sf::Color::Transparent);
		}

		_window.draw(pointsText);
		_window.draw(healthText);
		_window.draw(healthbar1);
		_window.draw(healthbar2);
		_window.draw(healthbar3);
		if (isDead)
		{
			_window.draw(deathText);
			if (!wasDead)
			{
				deathTimer.restart();
			}
			else
			{
				if (deathTimer.getElapsedTime().asSeconds() > 3)
				{
					_running = false;
				}
			}
		}

		for (CGameObject* currentObject : gameObjects)
		{
			currentObject->Tick(deltaTime);
			currentObject->drawTo(_window);
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
	enemy* enemyRef = new enemy();
	enemyRef->Load();
	enemyRef->setPosition(atPosition);
	x = (rand() % 1200) + 100;
	y = ((rand() % 300) + 100) * -1;
	addGameObject(enemyRef);

}

void CApplication::SpawnAsteroids(sf::Vector2f atPosition)
{
	Asteroids* AsteroidRef = new Asteroids();
	AsteroidRef->Load();
	AsteroidRef->setPosition(atPosition);
	x = (rand() % 1200) + 50;
	y = ((rand() % 600) + 100) * -1;
	addGameObject(AsteroidRef);
}

// add game objects to the game object vector
void CApplication::addGameObject(CGameObject* _gameObject)
{
	gameObjects.push_back(_gameObject);
}
