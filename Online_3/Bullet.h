#pragma once
#include "GameObject.h"
class Bullet : public GameObject
{
public:
	Bullet(LPCWSTR filename);
	void Move();
};

