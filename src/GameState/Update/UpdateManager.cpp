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

bool UpdateManager::AddItem(Updateable* item)
{
	// In a real engine these would be logged and in a hashmap
	if (item == nullptr)
		return false;

	// Prevent adding duplicates
	auto it = std::find(updateList.begin(), updateList.end(), item);
	if (it != updateList.end())
		return false;

	updateList.push_back(item);
	return true;
}

bool UpdateManager::RemoveItem(Updateable* item)
{
	// This will blow up the whole program if item is not found, maybe not
	auto it = std::find(updateList.begin(), updateList.end(), item);
	if (it != updateList.end())
	{
		updateList.erase(it);
		return true;
	}
	return false;

}
void UpdateManager::CalcDeltaTime()
{
	Uint64 currentTime = SDL_GetTicks();

	this->deltaTime = (currentTime - last_frame_time) / 1000.0f; // Convert milliseconds to seconds
}