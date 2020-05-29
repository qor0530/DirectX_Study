#pragma once
#include "GameObject.h"
#include "GraphicManager.h"
#include "Scene.h"
#include "GameScene.h"

enum SCENETYPE
{
	INTRO,
	MAIN,
	GAME,
	SCORE
};
class GameSystem
{
private:
	Scene* scene1 = nullptr;
	Scene* scene2 = nullptr;
public:
	void Init();
	void Update();
	void Render();
	void Release();
	void SetScene(int scenenumber);
};

