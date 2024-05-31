#include "scene_controller.h"

SceneController::SceneController() {
  loop_delay = {.tv_sec = 0, .tv_nsec = 30 * 1000 * 1000};
  render_controller = new RenderController();
  knobs_controller = new KnobsController();
  diod_controller = new DiodController();

  game_state = "main_menu";

  player = new Player(render_controller, knobs_controller, diod_controller);

  main_menu = new MainMenu(render_controller, knobs_controller);
  level = new Level(render_controller, knobs_controller, diod_controller, player);
  gameover_menu = new GameOverMenu(render_controller, knobs_controller);
  settings_menu = new SettingsMenu(render_controller, knobs_controller);
}

void SceneController::startGame() {
  while (1) {
    knobs_controller->update();

    if (game_state == "main_menu") {
      main_menu->setGameState(game_state);
      main_menu->draw();
      setGameState(main_menu->getGameState());

    } else if (game_state == "level") {
      level->setGameState(game_state);
      level->draw();
      setGameState(level->getGameState());

    } else if (game_state == "game_over") {
      gameover_menu->setGameState(game_state);
      gameover_menu->setScore(level->getScore());

      gameover_menu->draw();
      setGameState(gameover_menu->getGameState());

    } else if (game_state == "settings_menu") {
      settings_menu->setGameState(game_state);
      settings_menu->draw();
      setGameState(settings_menu->getGameState());
    }

    render_controller->update();

    clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
  }
}

std::string SceneController::getGameState() { return game_state; }

void SceneController::setGameState(std::string game_state) {
  this->game_state = game_state;
}
