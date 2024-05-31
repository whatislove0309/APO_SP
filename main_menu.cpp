#include "main_menu.h"

MainMenu::MainMenu(RenderController *render_controller, KnobsController *knobs_controller)
    : Scene::Scene(render_controller, knobs_controller) {
  game_state = "main_menu";
}

void MainMenu::draw() {
  render_controller->drawMainBackground();

  if (knobs_controller->is_red_pressed) {
    render_controller->higlightRegion(58, 145, 142, 35);
    setGameState("level");
  }
  if (knobs_controller->is_green_pressed) {
    render_controller->higlightRegion(58, 192, 142, 35);
  }
  if (knobs_controller->is_blue_pressed) {
    render_controller->higlightRegion(58, 240, 142, 35);
  }
}
