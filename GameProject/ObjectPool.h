#pragma once
#include "Projectile.h"

class CObjectPool
{
public:
	CObjectPool();


private:

	std::vector<CProjectile> magazine;

};