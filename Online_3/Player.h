#pragma once
#include "GameObject.h"
#include "Bullet.h"
class Player : public GameObject
{
private:
	Bullet* bullet[10];
	double count_bullet;
public:
	Player(LPCWSTR filename);
	void move();
	void Shot();
	void Render();
};

