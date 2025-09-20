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
	SDL_FRect* rect_ptr;


public:
	struct collision {
		const Collidable* coll_a;
		const Collidable* coll_b;
		SDL_FRect* intersect;

	};

	void checkCollision(const Collidable& other) {
		collision coll;
		if (SDL_GetRectIntersectionFloat(rect_ptr, other.rect_ptr, coll.intersect)) {
			coll.coll_a = this;
			coll.coll_b = &other;
			evaluateCollision(coll);
		}
	}
	//returns vector2 representing distance to move collidable out of other collider
	vector2 evaluateCollision(collision coll){
		vector2 v_out = vector2(coll.intersect->w, coll.intersect->h);
		if (v_out.x > v_out.y) {
			v_out.y = coll.intersect->y;
		}
		else {
			v_out.x = coll.intersect->x;
		}
		return v_out;
	}
	

};




