#pragma once
#include <SDL3/SDL.h>
#include <vector> 
#include "../GameObjects/Collidable.hpp"
#include "../Vector2.hpp"
#include "../GameObjects/Rigidbody.hpp"

class RigidWorld {
	
	RigidWorld();
	~RigidWorld() = default;
	//vector to hold all objects in a scene?
	public:
		static std::vector<Rigidbody> bodies;

		enum force_type {
			velocity,
			force,
			impulse
		};

		//check all in scene
		void CheckCollisions() {
			//get rect_a from iterator somehow.
			/*
			for (auto it = bodies.begin(); it != bodies.end(); it++){
				SDL_FRect rect_a = *it;
				for (int i = *it + 1; i < bodies.size(); i++) {
					SDL_FRect rect_b = bodies[i];
					if (SDL_HasRectIntersectionFloat(rect_a, rect_b)) {
						EvaluateCollision(it, bodies[i]);
					}
				}
			}
			*/
		}


		collision EvaluateCollision(Rigidbody rb1, Rigidbody rb2) {
			collision coll;
			return coll;
		}

		//uhm yeah idk this comes down to a higher power
		void PopulateColliderVect() {

		}

		//helper function for dummy "rect" GOs
		SDL_FRect DummyCollAdd() {
			SDL_FRect rect{};
			rect.x = SDL_rand(640);
			rect.y = SDL_rand(480);
			rect.w = 10 + SDL_rand(40);
			rect.h= 10 + SDL_rand(40);
			
			return rect;
		}
		//rect list fer testing purposes
		std::vector<SDL_FRect> rects;
		

};