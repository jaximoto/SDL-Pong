#pragma once
#include "GameObject.hpp"
#include "Updateable.hpp"

class UpdateableGameObject : public GameObject, public Updateable
{
	public:
		using GameObject::GameObject; // Inherit constructors directly

		virtual ~UpdateableGameObject() = default;
		virtual void update(float delta_time) = 0;

};
