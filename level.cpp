#include "level.h"

Level::Level() {
    game_state = "main_menu";
};

void Level::setRenderController(RenderController *render_controller) {
  this->render_controller = *render_controller;
}

void Level::draw() {
  render_controller.drawLevelBackground();
  render_controller.renderShip();
}

std::string Level::getGameState() { return game_state; }
