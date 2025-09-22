#pragma once
class Updateable
{
public:
    virtual void Update(float deltaTime) = 0;
	// still need a virtual destructor for proper cleanup of derived classes
    virtual ~Updateable() = default;
};
