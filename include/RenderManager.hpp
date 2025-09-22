#pragma once
#include <SDL3/SDL.h>
#include <Drawable.hpp>
#include <vector>
#include <algorithm>
class RenderManager {
	
	SDL_Window* window;
	int sWidth;
	int sHeight;
	int lWidth;
	int lHeight;
	Color bgColor;
	bool fullScreen;
public:
	std::vector<Drawable*> spriteList;
	SDL_Renderer* renderer;

	RenderManager(const char* title, int sWidth, int sHeight, int lWidth, int lHeight, bool fullScreen, Color bgColor = Color());
	~RenderManager();
	void Render();
	void AddObject(Drawable* obj) { spriteList.push_back(obj); }
	void ChangeBGColor(Color color);

private:
	void RenderObjects();
	void DestroyObjects();
};