#include "UpdateableGameObject.hpp"

class PlayerObject : public UpdateableGameObject
{
public:
    PlayerObject(float x, float y, float w, float h)
        : UpdateableGameObject(x, y, w, h)
    {
    }

    void Update(float delta_time) override
    {
        // Player-specific update logic
    }
};
