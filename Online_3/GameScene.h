#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "GraphicManager.h"
#include "Player.h"

class GameScene : public Scene
{
private:
	Player* player;
public:
	void Init();
	void Update();
	void Render();
	void Release();

};

