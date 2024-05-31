#include "bullet_controller.h"

BulletController::BulletController(RenderController *render_controller) {
  this->render_controller = render_controller;
}

void BulletController::draw() {
  for (Bullet *bullet : bullets) {
    if (!bullet->getIsOut()) {
      bullet->draw();
    }
  }
}

void BulletController::createBullet(int x, int y) {
  for (Bullet *bullet : bullets) {
    if (bullet->getIsOut()) {
      bullet->reset(x);
      return;
    }
  }

  bullets.push_back(new Bullet(render_controller, x));
}

void BulletController::shoot(int x1, int x2, int y) {
  auto now = std::chrono::steady_clock::now();
  if ((now - last_time) > bullet_delay) {
    createBullet(x1, y);
    createBullet(x2, y);
    last_time = now;
  }
}

std::vector<Bullet *> *BulletController::bulletsList() { 
  return &bullets; 
}

void BulletController::reset() {
  for (Bullet *bullet : bullets) {
    bullet->destroy();
  }
}
