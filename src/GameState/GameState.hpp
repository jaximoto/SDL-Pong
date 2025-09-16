#pragma once
#include <SDL3/SDL.h>
/*
This class will be the glue for all the manager classes

Need Renderer Manager
Need Update Manager
Need Input Manager
*/
class GameState
{
public:
	//RendererManager renderManager = new renderManager(SDL_Renderer* renderer, SDL_Window* window, int width, int height);
	GameState(SDL_Renderer* renderer, SDL_Window* window, int width, int height)
};