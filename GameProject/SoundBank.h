#pragma once
#include <SFML/Audio.hpp>

class CSoundBank // Singleton pattern
{
public:
	static CSoundBank& GetInstance()
	{
		static CSoundBank* _instance = nullptr;
		if (_instance == nullptr)
		{
			_instance = new CSoundBank();
		}
		return *_instance;
	}

	sf::Sound playerHitS;		// sound for when a player hits an enemy/asteroid
	sf::Sound enemyHitS;		// sound for when an enemy hits a player
	sf::Sound gameOverS;		// sound for gameOver

private:
	CSoundBank();

	sf::SoundBuffer playerHitSB;  // sound buffer same as sf::texture. Houses the data.
	sf::SoundBuffer enemyHitSB;
	sf::SoundBuffer gameOverSB;
};