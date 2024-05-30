#include "player.h"

Player::Player(RenderController *render_controller,
               KnobsController *knobs_controller,
               DiodController *diod_controller)
    : Player::Player(render_controller, 213, 238, 54, 62) {
  this->knobs_controller = knobs_controller;
  this->diod_controller = diod_controller;
  this->speed = 10;
  this->health = maxHealth;
  this->lastRecoveryTime = std::chrono::steady_clock::now();
}

void Player::draw() {
  using namespace std::chrono;
  diod_controller->diod(health);

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

  auto now = steady_clock::now();
  auto sinceLast = duration_cast<seconds>(now - lastRecoveryTime).count();
  if (sinceLast >= recoveryInterval) {
    recover();
    lastRecoveryTime = now;
  }

  render_controller->drawShip(x);
}

int Player::getHealth() { return health; }

void Player::damage() {
  if (health > 0)
    health--;
}

void Player::recover() {
  if (health < maxHealth) {
    health++;
  }
}
