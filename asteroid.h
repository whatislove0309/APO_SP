#pragma once
#include "entity.h"

class Asteroid:public Entity
{
private:
    bool is_out = false;
    int startY = 0;
public:
    using Entity::Entity;
    Asteroid(RenderController *render_controller, int x);
    void draw();
    bool getIsOut();
    void reset(int x);
    void destroy();
};
