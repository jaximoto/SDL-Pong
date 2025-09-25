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

UpdateableGameObject* GameState::CreateUpdateableGameObject(float x, float y, float w, float h)
{
	UpdateableGameObject* obj = new UpdateableGameObject(x, y, w, h);
	this->updateManager->AddUpdateable(obj);
	return obj;
}
DrawableGameObject* GameState::CreateDrawableGameObject(float x, float y, float w, float h,
	int drawOrder, Color color);
UDGameObject* GameState::CreateUDGameObject(float x, float y, float w, float h,
	int drawOrder, Color color);