#include "DrawableGameObject.hpp"

 DrawableGameObject::DrawableGameObject(float x, float y, float w, float h,
 int drawOrder,
	Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
	this->drawOrder = drawOrder;
}

void DrawableGameObject::Draw(SDL_Renderer* renderer){
	if (!SDL_SetRenderDrawColor(renderer, this->r, this->g, this->b, this->a)) {
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "Couldn't change renderer draw color: %s\n", SDL_GetError());
	};
	// needed to pass &this->rect instead of this->rect bc the function is expecting
	// a const, and we can pass a const reference to the rect bc func promises not to mutate
	if(!SDL_RenderFillRect(renderer, &this->rect))
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "Couldn't draw rect: %s\n", SDL_GetError());
}