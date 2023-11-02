#include "Application.h"
#include "TextureBank.h"
#include "player.h"
#include <SFML/Window/Event.hpp>

// Define the static member variable outside of the class
bool CApplication::isDead = false;

CApplication::CApplication(const sf::String& windowTitle, unsigned int windowWidth, unsigned int windowHeight)
    : _running(true), x(0), y(0)
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

    // Enemies
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

		healthText.setString(sf::String("HEALTH: ") + std::to_string(Player.getHealthPoints()));

		_window.draw(pointsText);
		_window.draw(healthText);
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
		// Collision detection between player and enemies
		for (enemy& enemyShip : Enemies)
		{
			if (Player.GetCollider().IsColliding(enemyShip.GetCollider()))
			{
				Player.decreaseHealth();
				// You can also implement other actions like removing the enemy.
			}
			// Check if the player has died
			if (Player.checkForDeath())
			{
				// Player has died, set the game state to "dead."
				isDead = true;
			}

			// Handle the enemy's damage and possible removal
			int projectileDamage = static_cast<int>(Player.GetProjectileDamage());
			enemyShip.DecreaseHealth(projectileDamage);

			// Check if the enemy has been defeated
			if (enemyShip.IsDefeated())
			{
				// Handle enemy death logic
				enemyShip.Death();
			}
		}
        // Update and render game objects
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
