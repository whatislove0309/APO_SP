#include "player.h"

Player::Player(RenderController *render_controller, 
  KnobsController *knobs_controller, DiodController *diod_controller)
    : Player::Player(render_controller, 213, 238, 54, 62) {
  this->knobs_controller = knobs_controller;
  this->diod_controller = diod_controller;
  this->speed = 10;
  this->health = maxHealth;
  printf("player diod controller: %p\n", diod_controller);
}

void Player::draw() {
  diod_controller->diod();
  if (knobs_controller->is_blue_pressed) {
    if (x < 480 - width) {
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

int Player::getHealth() {
  return health;
}

void Player::damage() {
  if (health > 0) health--;
} 
