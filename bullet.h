#pragma once
#include "entity.h"

class Bullet:public Entity
{
private:
    int x;
    int y = 320 - 64;
public:
    using Entity::Entity;
    Bullet(RenderController *render_controller, int x);
    void draw();
};
