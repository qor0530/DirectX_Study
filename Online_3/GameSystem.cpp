#include "GameSystem.h"

void GameSystem::Init()
{
	SetScene(SCENETYPE::GAME);
}

void GameSystem::Update()
{
	scene1->Update();
}

void GameSystem::Render()
{
	scene1->Render();
}

void GameSystem::Release()
{
	scene1->Release();
}

void GameSystem::SetScene(int scenenumber)
{
	if (scene1 != nullptr)
		scene1->Release();
	delete scene1;
		switch (scenenumber)
		{
		case SCENETYPE::GAME:
			scene1 = new GameScene();
			break;
		}
		if (scene1 != NULL)
		{
			scene1->Init();
		}
}
