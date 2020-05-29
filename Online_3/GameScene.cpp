#include "GameScene.h"

void GameScene::Init()
{
	player = new Player(L"1.png");
}

void GameScene::Update()
{
	player->move();
	player->Shot();
}

void GameScene::Render()
{
	player->Render();
}

void GameScene::Release()
{
	delete player;
}
