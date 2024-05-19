#include "player.h"

Player::Player(RenderController *render_controller, KnobsController *knobs_controller)
    : Player::Player(render_controller, 213, 238, 54, 62) {
  this->knobs_controller = knobs_controller;
  this->speed = 10;
}

void Player::draw() {
  if (knobs_controller->is_blue_pressed) {
    if (x < 450) {
      x += speed;
    }
  }
  if (knobs_controller->is_red_pressed) {
    if (x > 0) {
      x -= speed;
    }
  }
  if (knobs_controller->is_green_pressed) {
    createBullet();
  }
  render_controller->drawShip(x);
  bullets[0]->draw();
}

void Player::createBullet() {
    bullets.push_back(new Bullet(render_controller, x + width/2 - 10, 320 - height));
}
