#include "SoundBank.h"

CSoundBank::CSoundBank()
{
	playerHitSB.loadFromFile("Content/Audio/blaster.ogg");
	enemyHitSB.loadFromFile("Content/Audio/oof.ogg");
	gameOverSB.loadFromFile("Content/Audio/womp.ogg");

	playerHitS.setBuffer(playerHitSB);
	playerHitS.setVolume(10);
	enemyHitS.setBuffer(enemyHitSB);
	enemyHitS.setVolume(10);
	gameOverS.setBuffer(gameOverSB);
	gameOverS.setVolume(7);
}