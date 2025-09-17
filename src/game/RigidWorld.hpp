#pragma once
#include "Collidable.hpp"
#include <SDL3/SDL.h>
#include <vector> 
#include "Vector2.hpp"


class RigidWorld {
	//vector to hold all objects in a scene?
	static std::vector<Collidable*> colliders;
	std::vector<Collidable*>::iterator it;
	


	public:

		collision CheckCollisions() {
			//get rect_a from iterator somehow.
			SDL_FRect rect_a;
			//then for rect_b, do the same for each next?
			SDL_FRect rect_b;
			for (int i = 0; i < colliders.size(); i++) {

			}
		}

		void EvaluateCollision(collision coll) {

		}

};