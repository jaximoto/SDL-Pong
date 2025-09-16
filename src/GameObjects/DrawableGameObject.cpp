#include "DrawableGameObject.hpp"

DrawableGameObject DrawableGameObject::DrawableGameObject(float x, float y, float w, float h,
	SDL_Renderer* renderer, int drawOrder,
	Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	this->renderer = renderer;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
	this->drawOrder = drawOrder;
}

void Draw(SDL_Renderer* renderer) override {
	if (!SDL_SetRenderDrawColor(renderer, this->r, this->g, this->b, this->a)) {
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "Couldn't change renderer draw color: %s\n", SDL_GetError());
	};
	if(SDL_RenderFillRect(renderer, this->rect))
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "Couldn't draw rect: %s\n", SDL_GetError());
}