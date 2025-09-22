#pragma once
#include <SDL3/SDL.h>
#include <Updateable.hpp>
#include <UpdateableGameObject.hpp>
#include <vector>
class UpdateManager
{
	Uint64 last_frame_time;
	public:
		float deltaTime;
		std::vector<Updateable*> updateList;
		UpdateManager();
		~UpdateManager();
		void Update();

	private:
		void CalcDeltaTime();
};