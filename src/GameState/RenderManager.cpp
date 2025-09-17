#pragma once
#include "RenderManager.hpp"

RenderManager::RenderManager(const char* title, int sWidth, int sHeight, int lWidth, int lHeight, bool fullScreen) {
	this->renderer = nullptr;
	this->window = nullptr;
	this->sWidth = sWidth;
	this->sHeight = sHeight;
	this->lWidth = lWidth;
	this->lHeight = lHeight;
	this->fullScreen = fullScreen;
	int displayFlag = fullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_RESIZABLE;
	if (!SDL_CreateWindowAndRenderer(title, sWidth, sHeight, displayFlag, &window, &renderer))
		SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());

	/* Set logical size */
	if (!SDL_SetRenderLogicalPresentation(renderer, lWidth, lHeight, SDL_LOGICAL_PRESENTATION_LETTERBOX))
		SDL_Log("Couldn't set logical size: %s", SDL_GetError());
}
RenderManager::~RenderManager() {
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);

}


void RenderManager::RenderObjects() {
	std::sort(spriteList.begin(), spriteList.end(),
		[](Drawable* lhs, Drawable* rhs) {
			return lhs->drawOrder < rhs->drawOrder;
		});
	
	// needed to make a ptr using "*" to a interface not an actual element bc you can't instantiate abstract classes
	for (Drawable* it : spriteList) {
		it->Draw(this->renderer);
	}
}
void RenderManager::DestroyObjects() {
	for (auto obj : spriteList) {
		delete obj;
	}
	spriteList.clear();
}
