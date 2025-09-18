#pragma once
#include <SDL3/SDL.h>
#include <string>
#include <sstream>
#include "..\Vector2.hpp"

class Collidable {
	//from an architecture stand point what will happen
	//a GO will implement the collidable interface
	//the go has information pertaining to it's hitbox
	//we leave it alone. all we need to know is if should be 
	//added to the rigidbody pool

protected:
	bool is_trigger;

};
//basic collision struct
struct collision {
	Collidable* coll_a;
	Collidable* coll_b;
	vector2 pos;

	public:
		//gonna make a string constructor for collision data
		//altering dummies types first
		std::string toString() const {
			std::ostringstream ss;
			ss << "coll";
		}
};



//this will probably end up holding types of colliders
//and defining various collision types?



