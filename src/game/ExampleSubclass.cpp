#include "UpdateableGameObject.hpp"

class PlayerObject : public UpdateableGameObject
{
public:
    PlayerObject(float x, float y, float w, float h)
        : UpdateableGameObject(x, y, w, h)
    {
    }

    void update(float delta_time) override
    {
        // Player-specific update logic
    }
};
