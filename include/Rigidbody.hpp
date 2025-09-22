#pragma once
#include "Collidable.hpp"
#include "GameObject.hpp"
#include "..\Vector2.hpp"
#include "..\GameState\RigidWorld.hpp"

class Rigidbody : public Collidable
{	
	protected:
		GameObject* game_obj;
		
		bool dynamic = false;
		float mass = 1.0f;
		vector2 linear_velocity;
		


	public:
		Rigidbody(GameObject* go);
 
		
		/*
		void addForce(vector2 fvector, RigidWorld::force_type ftype) {
			
		}
		*/
		void isDynamic(bool dyna) {
			dynamic = dyna;
		}
		
};