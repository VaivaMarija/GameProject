#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>
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
	enemy Enemy;
	enemy Enemy2;


	void addGameObject(CGameObject* _gameObject);

private:
	void ProcessWindowEvent(const sf::Event& e);

	sf::RenderWindow _window;
	bool _running;

	// Projectile object to be able to spawn a projectile - move to player later
	CProjectile Projectile;

	std::vector<CGameObject*> gameObjects;
};