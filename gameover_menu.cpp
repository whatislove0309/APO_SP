#include "gameover_menu.h"

GameOverMenu::GameOverMenu(RenderController *render_controller, KnobsController *knobs_controller)
    : Scene::Scene(render_controller, knobs_controller) {
  this->score = score;
  game_state = "main_menu";
}

void GameOverMenu::draw() { 
    render_controller->drawGameOverBackground(); 
    drawScore();
}

void GameOverMenu::setScore(int score) { 
    this->score = score; 
}

void GameOverMenu::drawScore() {
  char buffer[10];
  sprintf(buffer, "%d", score);
  int width = render_controller->wordWidth(buffer);
  int x = 480 / 2 - width / 2;
  render_controller->drawText(x, 170, buffer, 0xfff, 3);
}
