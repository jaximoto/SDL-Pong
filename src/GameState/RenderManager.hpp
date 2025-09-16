#pragma once
#include <SDL3/SDL.h>
#include "GameObjects/DrawableGameObject.hpp"
#include <vector>
class RenderManager {
	SDL_Renderer* renderer;
	SDL_Window* window;
	std::vector<DrawableGameObject> spriteList;
	RenderManager(SDL_Renderer* renderer, SDL_Window* window, int width, int height);
};