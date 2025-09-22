#include "GameState.hpp"

GameState::GameState(const char* title, int sWidth, int sHeight, int lWidth, int lHeight, bool fullScreen) {
	this->renderManager = new RenderManager(title, sWidth, sHeight, lWidth, lHeight, fullScreen, Color::White);
	this->updateManager = new UpdateManager();
}

GameState::~GameState() {
	delete this->renderManager;
	delete this->updateManager;
}

void GameState::Update() {
	this->updateManager->Update();
}

void GameState::Render() {
	this->renderManager->Render();
}