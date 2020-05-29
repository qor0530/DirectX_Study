#include "GameScene.h"

void GameScene::Init()
{
	player = new GameObject;
	GraphicManager::Load_Bitmap(player, L"1.png");
}

void GameScene::Update()
{
	
}

void GameScene::Render()
{
	GraphicManager::Render(player);
}

void GameScene::Release()
{
	delete player;
}
