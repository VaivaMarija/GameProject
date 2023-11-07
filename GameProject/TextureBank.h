#pragma once
#include <SFML/Graphics/Texture.hpp>

#define LOAD_TEXTURE(texture, path) texture.loadFromFile( path ); texture.setSmooth(true);

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

	static sf::Texture playerHitT;				// texture for when a player hits an enemy/asteroid
	static sf::Texture enemyHitT;				// texture for when an enemy hits a player

	static sf::Texture backgroudT;				// Kasper the friendly swede



	static void loadAllTextures()
	{
		LOAD_TEXTURE(playerT, "Content/Textures/Player/playerShip1_blue.png");

		LOAD_TEXTURE(playerProjectileT, "Content/Textures/Lasers/laserBlue.png");
		LOAD_TEXTURE(playerProjectileHitT, "Content/Textures/Lasers/laserBlue_hit.png");

		LOAD_TEXTURE(playerPowerT, "Content/Textures/Lasers/laserGreen.png");
		LOAD_TEXTURE(playerPowerHitT, "Content/Textures/Lasers/laserGreen_hit.png");

		LOAD_TEXTURE(enemyT, "Content/Textures/Enemies/enemyBlack1.png");
		LOAD_TEXTURE(enemyProjectileT, "Content/Textures/Lasers/laserRed.png");
		LOAD_TEXTURE(enemyProjectileHitT, "Content/Textures/Lasers/laserRed_hit.png");

		LOAD_TEXTURE(meteorTinyT, "Content/Textures/Meteors/meteorBrown_tiny2.png");
		LOAD_TEXTURE(meteorSmallT, "Content/Textures/Meteors/meteorBrown_small2.png");
		LOAD_TEXTURE(meteorMediumT, "Content/Textures/Meteors/meteorBrown_med1.png");
		LOAD_TEXTURE(meteorBigT, "Content/Textures/Meteors/meteorBrown_big2.png");

		LOAD_TEXTURE(playerHitT, "Content/Textures/Lasers/laserBlue_hit.png");
		LOAD_TEXTURE(enemyHitT,"Content/Textures/Lasers/laserRed_hit.png");

		LOAD_TEXTURE(backgroudT, "Content/Textures/kasperrr.png");
	}

private:

};