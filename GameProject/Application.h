#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>
#include <vector>
#include "Enemy.h"
#include "Projectile.h"
#include "Player.h"

class CApplication
{
public:
	CApplication(const sf::String& windowTitle, unsigned int windowWidth, unsigned int windowHeight);
	~CApplication();

	void Run();
	player Player;
	
	
	std::vector<enemy>Enemies;


	void addGameObject(CGameObject* _gameObject);

private:
	void ProcessWindowEvent(const sf::Event& e);
	void SpawnEnemy(sf::Vector2f atPosition);

	int x;
	int y;
	sf::RenderWindow _window;
	bool _running;

	// Projectile object to be able to spawn a projectile - move to player later
	CProjectile Projectile;

	std::vector<CGameObject*> gameObjects;
};