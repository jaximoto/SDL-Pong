#pragma once
#include "GameObject.hpp"
#include "Drawable.hpp"
#include "Updateable.hpp"

class UDGameObject : public GameObject, public Drawable, public Updateable
{
public:
	SDL_Renderer* renderer;
	Uint8 r, g, b, a; // Color components
	int drawOrder; // Lower numbers drawn first
	UDGameObject(float x, float y, float w, float h,
		SDL_Renderer* renderer, int drawOrder,
		Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	// Still need a virtual destructor for proper cleanup of derived classes
	virtual ~UDGameObject() = default;
	virtual void Draw(SDL_Renderer* renderer) override;
	virtual void Update(float delta_time) override;

};
