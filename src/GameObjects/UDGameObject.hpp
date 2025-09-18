#pragma once
#include "GameObject.hpp"
#include "Drawable.hpp"
#include "Updateable.hpp"

class UDGameObject : public GameObject, public Drawable, public Updateable
{
public:
	Color color;
	int drawOrder; // Lower numbers drawn first
	UDGameObject(float x, float y, float w, float h,
		int drawOrder, Color color);
		

	// Still need a virtual destructor for proper cleanup of derived classes
	virtual ~UDGameObject() = default;
	virtual void Draw(SDL_Renderer* renderer) override;
	virtual void Update(float delta_time) override;

};
