#pragma once
class Updateable
{
public:
    virtual void update() = 0;
	// still need a virtual destructor for proper cleanup of derived classes
    virtual ~Updateable() = default;
};
