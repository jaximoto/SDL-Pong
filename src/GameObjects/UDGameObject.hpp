#pragma once
#include "GameObject.hpp"
#include "Drawable.hpp"
#include "Updateable.hpp"

class DrawableGameObject : public GameObject, public Drawable, public Updateable
{
public:
	SDL_Renderer* renderer;
	Uint8 r, g, b, a; // Color components
	int drawOrder; // Lower numbers drawn first
	DrawableGameObject(float x, float y, float w, float h,
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

	// Still need a virtual destructor for proper cleanup of derived classes
	virtual ~DrawableGameObject() = default;
	virtual void Draw(SDL_Renderer* renderer) = 0;
	virtual void update(float delta_time) = 0;

};
