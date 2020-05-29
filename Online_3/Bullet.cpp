#include "Bullet.h"

Bullet::Bullet(LPCWSTR filename) : GameObject(filename)
{
	
}

void Bullet::Move()
{
	position.y -= 10;
}
