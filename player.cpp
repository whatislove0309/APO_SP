#include "player.h"

Player::Player(int x, int y, int width, int height, int speed):
    Player::Player(x, y, width, height) {
    this->speed = speed;
}

void Player::draw() {
  if (knobs_controller->is_red_pressed) {
    if (x < 450) {
      x += speed;
    }
  }
  if (knobs_controller->is_blue_pressed) {
    if (x > 0) {
      x -= speed;
    }
  }
  render_controller->drawShip(x, width);
}

void Player::setKnobsController(KnobsController *knobsController) {
  this->knobs_controller = knobs_controller;
}
