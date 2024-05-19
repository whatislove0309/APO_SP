#include "bullet.h"

Bullet::Bullet(RenderController *render_controller, int x, int y)
    :Entity::Entity(render_controller,x, y, 10, 20 ) {
    
    while (y > 0) {
        render_controller->drawBullet(x, y);
        y-=10;
    }
}