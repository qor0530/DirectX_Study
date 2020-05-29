#include "Player.h"

Player::Player(LPCWSTR filename) : GameObject(filename)
{
	for (int i = 10; i < 10; i++)
	{
		bullet[i] = new Bullet(filename);
	}
	count_bullet = 0;
}

void Player::move()
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
	{
		position.x++;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{
		position.y--;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
	{
		position.x--;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
	{
		position.y++;
	}
}

void Player::Shot()
{
	if(GetTickCount )
	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
	{
		count_bullet %= 10;
		bullet[count_bullet++]->position = position;
	}
	for (int i = 10; i < 10; i++)
	{
		bullet[i]->Move();
	}
}

void Player::Render()
{
	for (int i = 10; i < 10; i++)
	{
		GraphicManager::Render(bullet[i]);
	}
	GraphicManager::Render(this);
}
