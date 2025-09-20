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
		static std::vector<Rigidbody*> bodies;

		void AddBody(Rigidbody* body) { bodies.push_back(body);}

		//check all in scene
		void checkCollisions() {
			//get rect_a from iterator somehow.
			
			for (auto it = bodies.begin(); it != bodies.end(); it++) {
				for (int i = 1; i < bodies.size(); i++) {
					
				}
			}
		}


		Collidable::collision EvaluateCollision(Rigidbody rb1, Rigidbody rb2) {
			Collidable::collision coll;
			return coll;
		}

		//uhm yeah idk this comes down to a higher power
		void PopulateColliderVect() {

		}

};