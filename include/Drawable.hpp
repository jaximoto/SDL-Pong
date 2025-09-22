#pragma once
#include "Color.hpp"
class Drawable
{
public:
    int drawOrder = 0;
    virtual void Draw(SDL_Renderer* renderer) = 0;
    // still need a virtual destructor for proper cleanup of derived classes
    virtual ~Drawable() = default;
};


