#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>
#include "Enemy.h"
#include "Projectile.h"

class CApplication
{
public:
	CApplication(const sf::String& windowTitle, unsigned int windowWidth, unsigned int windowHeight);
	~CApplication();

	void Run();
	
	enemy Enemy;
	enemy Enemy2;

private:
	void ProcessWindowEvent(const sf::Event& e);

	sf::RenderWindow _window;
	bool _running;

	// Projectile object to be able to spawn a projectile - move to player later
	CProjectile Projectile;



	// delta time function
};