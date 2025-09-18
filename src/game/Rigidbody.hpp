#pragma once
#include "Vector2.hpp"
#include "Collidable.hpp"
#include "RigidWorld.hpp"

class Rigidbody : public Collidable
{	
	protected:
		vector2 position;
		bool dynamic;
		float mass = 1.0f;
		vector2 linear_velocity;
		


	public: 
		void addForce(vector2 fvector, RigidWorld::force_type ftype) {
			
		}

		 
};