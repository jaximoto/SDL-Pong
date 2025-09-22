#pragma once
#include "GameObject.hpp"
#include "Drawable.hpp"

class DrawableGameObject : public GameObject, public Drawable
{
public:
	Color color;
	int drawOrder; // Lower numbers drawn first
	DrawableGameObject(float x, float y, float w, float h,
		int drawOrder, Color color);


	// Still need a virtual destructor for proper cleanup of derived classes
	virtual ~DrawableGameObject() = default;
	void Draw(SDL_Renderer* renderer) override;

};
