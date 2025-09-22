#pragma once
#include "GameObject.hpp"
#include "Updateable.hpp"

class UpdateableGameObject : public GameObject, public Updateable
{
	public:
		using GameObject::GameObject; // Inherit constructors directly

		// Still need a virtual destructor for proper cleanup of derived classes
		virtual ~UpdateableGameObject() = default;
		virtual void Update(float deltaTime) override;

};
