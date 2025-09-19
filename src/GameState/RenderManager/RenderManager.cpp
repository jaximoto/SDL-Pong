#pragma once
#include "RenderManager.hpp"

RenderManager::RenderManager(const char* title, int sWidth, int sHeight, int lWidth, int lHeight, bool fullScreen, Color bgColor) {
	this->renderer = nullptr;
	this->window = nullptr;
	this->sWidth = sWidth;
	this->sHeight = sHeight;
	this->lWidth = lWidth;
	this->lHeight = lHeight;
	this->fullScreen = fullScreen;
	this->bgColor = bgColor;
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
	DestroyObjects();

}


void RenderManager::RenderObjects() {
	// first render bg:
	if (!SDL_SetRenderDrawColor(renderer, this->bgColor.r, this->bgColor.g, this->bgColor.b, this->bgColor.a)) {
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "Couldn't change renderer draw color: %s\n", SDL_GetError());
	};

	if(!SDL_RenderClear(this->renderer))
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "Couldn't draw over background: %s\n", SDL_GetError());

	std::sort(spriteList.begin(), spriteList.end(),
		[](Drawable* lhs, Drawable* rhs) {
			return lhs->drawOrder < rhs->drawOrder;
		});
	
	// needed to make a ptr using "*" to a interface not an actual element bc you can't instantiate abstract classes
	for (Drawable* it : spriteList) {
		it->Draw(this->renderer);
	}

	SDL_RenderPresent(this->renderer);
}
void RenderManager::ChangeBGColor(Color color) {
	this->bgColor = color;
}
void RenderManager::Render() {
	RenderObjects();
}

void RenderManager::DestroyObjects() {
	for (auto obj : spriteList) {
		delete obj;
	}
	spriteList.clear();
}
