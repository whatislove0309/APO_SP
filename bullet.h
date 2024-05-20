#pragma once
#include "entity.h"

class Bullet:public Entity
{
private:
    int x;
    int y = 320 - 64;
    int startY = 320 - 64;
    bool is_out = false;
public:
    using Entity::Entity;
    Bullet(RenderController *render_controller, int x);
    void reset(int x);
    void draw();
    bool getIsOut();
    void destroy();
};
