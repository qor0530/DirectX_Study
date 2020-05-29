#include "GameSystem.h"

void GameSystem::Init()
{
	obj = new GameObject;
	GraphicManager::Load_Bitmap(obj, L"1.png");
}

void GameSystem::Update()
{
}

void GameSystem::Render()
{
	GraphicManager::Render(obj);
}

void GameSystem::Release()
{
	delete obj;
}
