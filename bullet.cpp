#include "bullet.h"

Bullet::Bullet(RenderController *render_controller, int x)
    : Entity::Entity(render_controller, x, 320, 3, 10) {
  this->x = x;
}

void Bullet::draw() {
  y -= 10;
  if (y > 0) {
    render_controller->drawBullet(x, y, width, height);
  } else {
    is_out = true;
  }
}

bool Bullet::getIsOut() { 
    return is_out; 
}

void Bullet::reset(int x) {
  this->x = x;
  this->y = startY;
  this->is_out = false;
}

void Bullet::destroy() { 
    is_out = true; 
}

int Bullet::getY() { 
    return y; 
}

int Bullet::getX() { 
    return x; 
}
