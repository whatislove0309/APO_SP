#include "asteroid.h"

Asteroid::Asteroid(RenderController *render_controller, int x)
    : Entity::Entity(render_controller, x, 0, 21, 21)
{
    this->x = x;
}

void Asteroid::draw()
{
    y += 5;
    if (y < 320 + height)
    {
        render_controller->drawAsteroid(x, y);
    }
    else
    {
        is_out = true;
    }
}

bool Asteroid::getIsOut()
{
    return is_out;
}

void Asteroid::reset(int x)
{
    this->x = x;
    this->y = startY;
    this->is_out = false;
}

void Asteroid::destroy() {
    is_out = true;
}
