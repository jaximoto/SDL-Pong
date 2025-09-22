#pragma once
#include <SDL3/SDL.h>
#include <Updateable.hpp>
#include <UpdateableGameObject.hpp>
#include <vector>
class UpdateManager
{
	public:
		vector<Updateable*> updateList;
		UpdateManager() = default;
		~UpdateManager() = default;
		void Update();
};