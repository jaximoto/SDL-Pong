#pragma once
#include <SDL3/SDL.h>
#include "../GameObjects/Drawable.hpp"
#include <vector>
#include <algorithm>
class RenderManager {
	
	SDL_Window* window;
	int sWidth;
	int sHeight;
	int lWidth;
	int lHeight;
	bool fullScreen;
public:
	std::vector<Drawable*> spriteList;
	SDL_Renderer* renderer;

	RenderManager(const char* title, int sWidth, int sHeight, int lWidth, int lHeight, bool fullScreen);
	~RenderManager();
	void RenderObjects();
	void RenderDone();
	void AddObject(Drawable* obj) { spriteList.push_back(obj); }

private:
	void DestroyObjects();
};