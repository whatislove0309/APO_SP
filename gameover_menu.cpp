#include "gameover_menu.h"

GameOverMenu::GameOverMenu(RenderController *render_controller, KnobsController *knobs_controller)
    : Scene::Scene(render_controller, knobs_controller) {
  this->score = score;
  game_state = "game_over";
}

void GameOverMenu::draw() { 
    render_controller->drawGameOverBackground(); 
    render_controller->drawText(115, 280, "Main Menu", 0xfff, 2);
    drawScore();

    if (knobs_controller->is_green_pressed) {
      setGameState("main_menu");
      knobs_controller->disable(1);
    }
}

void GameOverMenu::setScore(int score) { 
    this->score = score; 
}

void GameOverMenu::drawScore() {
  char buffer[10];
  sprintf(buffer, "%d", score);
  int width = render_controller->wordWidth(buffer);
  int x = 480 / 2 - width * 1.5;
  render_controller->drawText(x, 200, buffer, 0xfff, 3);
}
