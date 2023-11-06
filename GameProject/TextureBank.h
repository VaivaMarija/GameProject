#pragma once
#include <SFML/Graphics/Texture.hpp>

class CTextureBank
{
public:
	static sf::Texture playerT;					// texture for player
	static sf::Texture playerProjectileT;		// texture for player projectile
	static sf::Texture playerProjectileHitT;	// texture for player projectile hit

	static sf::Texture playerPowerT;			// texture for player projectile when powered-up
	static sf::Texture playerPowerHitT; 		// texture for player projectile when powered-up hit

	static sf::Texture enemyT;					// texture for enemy
	static sf::Texture enemyProjectileT;		// texture for enemy projectile
	static sf::Texture enemyProjectileHitT;		// texture for enemy projectile when hit

	static sf::Texture meteorTinyT;				// texture for a tiny meteor
	static sf::Texture meteorSmallT;			// texture for a small meteor
	static sf::Texture meteorMediumT;			// texture for a medium meteor
	static sf::Texture meteorBigT;				// texture for a big meteor

	static sf::Texture backgroud;				// Kasper the friendly swede

	static void loadAllTextures()
	{
		playerT.loadFromFile("Content/Textures/Player/playerShip1_blue.png");
		playerProjectileT.loadFromFile("Content/Textures/Lasers/laserBlue.png");
		playerProjectileHitT.loadFromFile("Content/Textures/Lasers/laserBlue_hit.png");

		playerPowerT.loadFromFile("Content/Textures/Lasers/laserGreen.png");
		playerPowerHitT.loadFromFile("Content/Textures/Lasers/laserGreen_hit.png");

		enemyT.loadFromFile("Content/Textures/Enemies/enemyBlack1.png");
		enemyProjectileT.loadFromFile("Content/Textures/Lasers/laserRed.png");
		enemyProjectileHitT.loadFromFile("Content/Textures/Lasers/laserRed_hit.png");

		meteorTinyT.loadFromFile("Content/Textures/Meteors/meteorBrown_tiny2.png");
		meteorSmallT.loadFromFile("Content/Textures/Meteors/meteorBrown_small2.png");
		meteorMediumT.loadFromFile("Content/Textures/Meteors/meteorBrown_med1.png");
		meteorBigT.loadFromFile("Content/Textures/Meteors/meteorBrown_big2.png");

		backgroud.loadFromFile("Content/Textures/kasperrr.png");
	}

private:

};
