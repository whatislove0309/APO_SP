#include "player.h"

void Player::draw() {
  knobs_controller->update();
  if (knobs_controller->is_red_pressed) {
    if (x < 450) {
      x += 3;
    }
  }
  if (knobs_controller->is_blue_pressed) {
    if (x > 0) {
      x -= 3;
    }
  }
  render_controller->drawShip(x, width);
}

void Player::setKnobsController(KnobsController *knobsController) {
  this->knobs_controller = knobs_controller;
}
