#pragma once
#include <SDL3/SDL.h>
class GameObject
{
	protected:
		// Protected member variables:
		GameObject(float x = 0, float y = 0, float width = 50, float height = 50);
	public:
		// Member variables:
		SDL_FRect rect;

		// Destructor:
		
		virtual ~GameObject() = default;


		// Member functions:
		void Translate(float x, float y);
		// No rotation for now, bc can't rotate rects
		void Scale(float factor);

		void Morph(float width, float height);
};