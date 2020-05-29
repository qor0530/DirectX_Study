#pragma once
#include "GraphicManager.h"
class GameSystem
{
private:
	GameObject *obj;

public:
	void Init();
	void Update();
	void Render();
	void Release();
};

