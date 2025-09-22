#include <UpdateManager.hpp>
UpdateManager::UpdateManager()
	:last_frame_time(SDL_GetTicks()), deltaTime(last_frame_time)

{ }

UpdateManager::~UpdateManager()
{
	for (auto obj : updateList)
	{
		if (obj == nullptr)
			continue;
		delete obj;
		obj = nullptr;
	}
	updateList.clear();
}

void UpdateManager::Update() {
	CalcDeltaTime();
	for (Updateable* it : updateList)
	{
		it->Update(this->deltaTime);
	}
}

void UpdateManager::CalcDeltaTime()
{
	Uint64 currentTime = SDL_GetTicks();

	this->deltaTime = (currentTime - last_frame_time) / 1000.0f; // Convert milliseconds to seconds
}