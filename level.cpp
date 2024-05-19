#include "level.h"

Level::Level() { game_state = "main_menu"; };

void Level::setRenderController(RenderController *render_controller) {
  this->render_controller = *render_controller;
}

void Level::draw() {
  render_controller.drawLevelBackground();

  if (knobs_controller.is_red_pressed) {
    if (playerX < 450) {
      playerX += 3;
    }
  }
  if (knobs_controller.is_blue_pressed) {
    if (playerX > 0) {
      playerX -= 3;
    }
  }

  render_controller.renderShip(playerX);
}

void Level::setKnobsController(KnobsController *knobs_controller) {
  this->knobs_controller = *knobs_controller;
}

std::string Level::getGameState() { return game_state; }
