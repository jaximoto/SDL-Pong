#pragma once
#include "GameObject.hpp"
#include "Drawable.hpp"

class DrawableGameObject : public GameObject, public Drawable
{
public:
	Uint8 r, g, b, a; // Color components
	int drawOrder; // Lower numbers drawn first
	DrawableGameObject(float x, float y, float w, float h,
		 int drawOrder,
		Uint8 r, Uint8 g, Uint8 b, Uint8 a);


	// Still need a virtual destructor for proper cleanup of derived classes
	virtual ~DrawableGameObject() = default;
	void Draw(SDL_Renderer* renderer) override;

};
