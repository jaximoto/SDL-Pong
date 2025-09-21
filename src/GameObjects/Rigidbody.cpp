#include "Rigidbody.hpp"

Rigidbody::Rigidbody(GameObject* go) {
	this.game_obj = go; 
	this.rect_ptr = game_obj.rect;
}