#pragma once
#include "GameObject.h"
#include <vector>
class CollisionManager
{

public:
	void AddGameObject(CGameObject* gameObject);
	void CheckForCollisions();
	std::vector<CGameObject*> Enemies;
	std::vector<CGameObject*> PlayerProjectiles;
	std::vector<CGameObject*> Asteroids;
	//std::vector<CGameObject*>
private:
};

