#include "UDGameObject.hpp"

UDGameObject::UDGameObject(float x, float y, float w, float h,
	int drawOrder, Color color)
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	this->color = color;
	this->drawOrder = drawOrder;
}

void UDGameObject::Draw(SDL_Renderer* renderer){
	if (!SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, this->color.a)) {
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "Couldn't change renderer draw color: %s\n", SDL_GetError());
	};
	// needed to pass &this->rect instead of this->rect bc the function is expecting
	// a const, and we can pass a const reference to the rect bc func promises not to mutate
	if(!SDL_RenderFillRect(renderer, &this->rect))
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "Couldn't draw rect: %s\n", SDL_GetError());
}

void UDGameObject::Update(float delta_time) {
	SDL_Log("Updating UDGameObject with delta_time: %f\n", delta_time);
}