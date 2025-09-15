#pragma once
class Drawable
{
public:
    virtual void Draw() = 0;
    // still need a virtual destructor for proper cleanup of derived classes
    virtual ~Drawable() = default;
};
