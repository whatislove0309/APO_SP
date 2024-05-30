#include "gameover_menu.h"

GameOverMenu::GameOverMenu(RenderController *render_controller, KnobsController *knobs_controller)
  : Scene::Scene(render_controller, knobs_controller) 
{
  game_state = "main_menu";
}

void GameOverMenu::draw() {
  render_controller->drawGameOverBackground();
}