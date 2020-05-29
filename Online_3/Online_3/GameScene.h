#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "GraphicManager.h"
class GameScene : public Scene
{
private:
	GameObject* player;
public:
	void Init();
	void Update();
	void Render();
	void Release();

};

