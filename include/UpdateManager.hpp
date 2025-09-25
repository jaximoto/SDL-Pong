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
		// TODO Make it an unordered set for faster lookup / removal / insertion
		std::vector<Updateable*> updateList;
		UpdateManager();
		~UpdateManager();
		void Update();
		bool AddItem(Updateable* item)
		bool RemoveItem(Updateable* item);
			

	private:
		void CalcDeltaTime();
};