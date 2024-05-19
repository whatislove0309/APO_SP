#include "main_menu.h"

MainMenu::MainMenu() {
    game_state = "main_menu";
}

void MainMenu::setRenderController(RenderController *render_controller) {
  this->render_controller = *render_controller;
}

void MainMenu::draw() {
  render_controller.drawMainBackground();
  knobs_controller.update();

  if (knobs_controller.is_red_pressed) {
    render_controller.higlightRegion(58, 145, 142, 35);
    game_state = "level";
  }
  if (knobs_controller.is_green_pressed) {
    render_controller.higlightRegion(58, 192, 142, 35);
  }
  if (knobs_controller.is_blue_pressed) {
    render_controller.higlightRegion(58, 240, 142, 35);
  }
}

std::string MainMenu::getGameState() { return game_state; }
