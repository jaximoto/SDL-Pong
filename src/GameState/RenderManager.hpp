#pragma once
#include <SDL3/SDL.h>
#include "../GameObjects/Drawable.hpp"
#include <vector>
#include <algorithm>
class RenderManager {
	SDL_Renderer* renderer;
	SDL_Window* window;
	int sWidth;
	int sHeight;
	int lWidth;
	int lHeight;
	bool fullScreen;
public:
	std::vector<Drawable*> spriteList;

	RenderManager(const char* title, int sWidth, int sHeight, int lWidth, int lHeight, bool fullScreen);
	~RenderManager();

private:
	void RenderObjects();
	void DestroyObjects();
};