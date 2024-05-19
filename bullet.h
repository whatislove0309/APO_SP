#pragma once
#include "entity.h"

class Bullet:public Entity
{
private:
    int x, y;
public:
    using Entity::Entity;
    Bullet(RenderController *render_controller, int x, int y);
    void move();
};
