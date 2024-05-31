#include "settings_menu.h"

SettingsMenu::SettingsMenu(RenderController *render_controller, KnobsController *knobs_controller, Player *player)
    : Scene::Scene(render_controller, knobs_controller) {
  game_state = "main_menu";
  this->player = player;
}

void SettingsMenu::draw() {
  render_controller->drawSettingsBackground();

  if (knobs_controller->is_red_pressed) {
    render_controller->higlightRegion(26, 116, 110, 128);
    player->setSkin(1);
    knobs_controller->disable(1);
    setGameState("main_menu");
  }
  if (knobs_controller->is_green_pressed) {
    render_controller->higlightRegion(177, 116, 128, 128);
    player->setSkin(2);
    knobs_controller->disable(1);
    setGameState("main_menu");
  }
  if (knobs_controller->is_blue_pressed) {
    render_controller->higlightRegion(342, 116, 128, 128);
    player->setSkin(3);
    knobs_controller->disable(1);
    setGameState("main_menu");
  }
}
