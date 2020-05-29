#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "GraphicManager.h"
class MainScene : public Scene
{
private:
	GameObject* player2;
public:
	void Init();
	void Update();
	void Render();
	void Release();

};

