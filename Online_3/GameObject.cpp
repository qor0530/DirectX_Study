#include "GameObject.h"

GameObject::GameObject(LPCWSTR filename)
{
	position = { 400, 400 };
	angle = 45;
	scale = { 1, 1 };
	GraphicManager::Load_Bitmap(this, filename);
}

GameObject::~GameObject()
{
}
