#include "MainScene.h"

void MainScene::Init()
{
	player2 = new GameObject;
	GraphicManager::Load_Bitmap(player2, L"2.png");
}

void MainScene::Update()
{
}

void MainScene::Render()
{
	GraphicManager::Render(player2);
}

void MainScene::Release()
{
	delete player2;
}
