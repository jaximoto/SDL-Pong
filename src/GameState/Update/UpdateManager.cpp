#include <Updateable.hpp>
void UpdateManager::Update() {
	for (Updateable* it : spriteList)
	{
		it->Update();
}