#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>
#include <vector>
#include "Enemy.h"
#include "Projectile.h"
#include "Player.h"
#include <SFML/System/Clock.hpp>
#include "Asteroids.h"

class CApplication
{
public:
	CApplication(const sf::String& windowTitle, unsigned int windowWidth, unsigned int windowHeight);
	~CApplication();

	void Run();
	
	static void setIsDead(bool _isTrue);
	bool getIsDead();
	void setRestart(bool _true);
	bool getRestart();
	std::vector<enemy>Enemies;
	std::vector<Asteroids>asteroids;

	void addGameObject(CGameObject* _gameObject);

private:
	void ProcessWindowEvent(const sf::Event& e);
	void SpawnEnemy(CProjectilePool& enemyProjectilePool);
	void SpawnAsteroids(sf::Vector2f atPosition);

	int x;
	int y;
	sf::RenderWindow _window;
	bool _running;
	bool restart;
	static bool isDead;

	std::vector<CGameObject*> gameObjects;

};