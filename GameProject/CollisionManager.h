#pragma once
#include "GameObject.h"
#include <vector>
#include "player.h"

class CollisionManager
{

public:
	void AddGameObject(CGameObject* gameObject);
	void CheckForCollisions();

	void setPlayer(player* _playerObject);
private:
	std::vector<CGameObject*> Enemies;
	std::vector<CGameObject*> PlayerProjectiles;
	std::vector<CGameObject*> Asteroids;
	std::vector<CGameObject*> EnemyProjectiles;
	
	player* playerObject;
};

