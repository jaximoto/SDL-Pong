#pragma once
#include <SDL3/SDL.h>
#include <RenderManager.hpp>
#include <UpdateManager.hpp>
/*
This class will be the glue for all the manager classes

Need Renderer Manager
Need Update Manager
Need Input Manager
*/
class GameState
{
public:
	RenderManager* renderManager;
	UpdateManager* updateManager;
	GameState(const char* title, int sWidth, int sHeight, int lWidth, int lHeight, bool fullScreen);
	~GameState();
	void Update();
	void Render();
};