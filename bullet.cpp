#include "bullet.h"

Bullet::Bullet(RenderController *render_controller, int x)
    :Entity::Entity(render_controller,x, y, 10, 20 ) {
}

void Bullet::draw() {
    y-=10;
    render_controller->drawBullet(x, y);
}
