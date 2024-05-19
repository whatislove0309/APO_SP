#include "player.h"

Player::Player(RenderController *render_controller, int x, int y, int width,
               int height, int speed, KnobsController *knobs_controller)
    : Player::Player(render_controller, x, y, width, height) {
  this->knobs_controller = knobs_controller;
  this->speed = speed;
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
  render_controller->drawShip(x);
}
