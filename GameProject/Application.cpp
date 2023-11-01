#include "Application.h"
#include "TextureBank.h"
#include <SFML/Window/Event.hpp>

// Define the static member variable outside of the class
bool CApplication::isDead = false;

CApplication::CApplication(const sf::String& windowTitle, unsigned int windowWidth, unsigned int windowHeight)
    : _running(true), x(0), y(0)
{
    isDead = false; // Set isDead to false here
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

    sf::Event e;
    Player.setApplication(this);
    Player.Load();
    Player.setPlayerPos(sf::Vector2f(800, 450));

    //enemies
    Enemies.reserve(10);
    SpawnEnemy(sf::Vector2f(200, 80));
    SpawnEnemy(sf::Vector2f(x, y));
    SpawnEnemy(sf::Vector2f(x, y));
    SpawnEnemy(sf::Vector2f(x, y));
    SpawnEnemy(sf::Vector2f(x, y));

    // projectile
    TextureBank::loadAllTextures();
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
        // Measure elapsed time
        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        // Handle window events
        while (_window.pollEvent(e))
        {
            ProcessWindowEvent(e);
        }

        _window.clear(sf::Color::Black);

        // Update player
        Player.Tick(deltaTime);

        // Collision detection between player and enemies
        for (enemy& enemyShip : Enemies)
        {
            if (Player.GetCollider().IsColliding(enemyShip.GetCollider()))
            {
                Player.decreaseHealth();
                // You can also implement other actions like removing the enemy.
            }
        }

        // Update and render game objects
        for (CGameObject* currentObject : gameObjects)
        {
            currentObject->Tick(deltaTime);
            currentObject->drawTo(_window);
        }

        // Update and render enemies
        for (enemy& e : Enemies)
        {
            e.Tick(deltaTime);
            e.renderTo(_window);
        }

        // Render player
        Player.renderTo(_window);

        // Display the window
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
    enemy& enemyRef = Enemies.emplace_back();
    enemyRef.Load();
    // Generate random coordinates here
    float x = static_cast<float>(rand() % 1200) + 100;
    float y = static_cast<float>(rand() % 300) + 100;
    enemyRef.setEnemyPos(sf::Vector2f(x, y));
}

void CApplication::addGameObject(CGameObject* _gameObject)
{
    gameObjects.push_back(_gameObject);
}
