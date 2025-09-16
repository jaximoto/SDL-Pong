#pragma once
#include <SDL3/SDL.h>
class Drawable
{
public:
    int drawOrder = 0;
    virtual void Draw(SDL_Renderer* renderer) = 0;
    // still need a virtual destructor for proper cleanup of derived classes
    virtual ~Drawable() = default;
};
