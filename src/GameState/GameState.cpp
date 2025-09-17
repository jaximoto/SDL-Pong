#include "GameState.hpp"

GameState::GameState(const char* title, int sWidth, int sHeight, int lWidth, int lHeight, bool fullScreen) {
	this->renderManager = new RenderManager(title, sWidth, sHeight, lWidth, lHeight, fullScreen);
}

GameState::~GameState() {
	delete this->renderManager;
}