#include "scene_controller.h"

SceneController::SceneController() {
  loop_delay = {.tv_sec = 0, .tv_nsec = 30 * 1000 * 1000};
  render_controller = RenderController();

  game_state = "main_menu";

  main_menu = MainMenu();
  main_menu.setRenderController(&render_controller);

  level = Level();
  level.setRenderController(&render_controller);
}

void SceneController::startGame() {
  while (1) {
    if (game_state == "main_menu") {
      main_menu.draw();
      setGameState(main_menu.getGameState());

    } else if (game_state == "level") {
      level.draw();

    } else if (game_state == "settings_menu") {

    } else if (game_state == "score_menu") {
    }

    render_controller.update();

    clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
  }
}

std::string SceneController::getGameState() { return game_state; }

void SceneController::setGameState(std::string game_state) {
  this->game_state = game_state;
}
