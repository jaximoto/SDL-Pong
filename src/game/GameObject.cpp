#include "GameObject.hpp"


GameObject::GameObject(float x, float y, float width, float height){
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
}
void GameObject::translate(float x, float y)
{
	rect.x += x;
	rect.y += y;
}

void GameObject::scale(float factor)
{
	rect.w *= factor;
	rect.h *= factor;
}

