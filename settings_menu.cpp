#include "settings_menu.h"

SettingsMenu::SettingsMenu(RenderController *render_controller, KnobsController *knobs_controller, Player *player)
    : Scene::Scene(render_controller, knobs_controller) {
  game_state = "main_menu";
  this->player = player;
}

void SettingsMenu::draw() {
  render_controller->drawLevelBackground();

  if (knobs_controller->is_red_pressed) {
    render_controller->higlightRegion(58, 145, 142, 35);
    knobs_controller->disable(1);
    player->setSkin(1);
    setGameState("main_menu");
  }
  if (knobs_controller->is_green_pressed) {
    render_controller->higlightRegion(58, 192, 142, 35);
    knobs_controller->disable(1);
    player->setSkin(2);
    setGameState("main_menu");
  }
  if (knobs_controller->is_blue_pressed) {
    render_controller->higlightRegion(58, 240, 142, 35);
    knobs_controller->disable(1);
    player->setSkin(3);
    setGameState("main_menu");
  }
}
