#include "GameObject.hpp"


GameObject::GameObject(float x, float y, float width, float height){
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
}
void GameObject::Translate(float x, float y)
{
	rect.x += x;
	rect.y += y;
}

void GameObject::Scale(float factor)
{
	rect.w *= factor;
	rect.h *= factor;
}

void GameObject::Morph(float width, float height)
{
	rect.w = width;
	rect.h = height;
}

