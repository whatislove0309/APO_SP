#include "bullet.h"

Bullet::Bullet(RenderController *render_controller, int x, int y)
    : Entity::Entity(render_controller, x, y, 3, 10)
{
    this->x = x;
    this->y = y;
}

void Bullet::draw()
{
    y -= 10;
    if (y > 0)
    {
        render_controller->drawBullet(x, y, width, height);
    }
    else
    {
        is_out = true;
    }
}

bool Bullet::getIsOut()
{
    return is_out;
}

void Bullet::reset(int x)
{
    this->x = x;
    this->is_out = false;
    this->y = startY;
}

void Bullet::destroy() {
    is_out = true;
}
