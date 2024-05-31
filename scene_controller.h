#pragma once

#include <iostream>
#include <time.h>

#include "diod_controller.h"
#include "gameover_menu.h"
#include "knobs_controller.h"
#include "level.h"
#include "main_menu.h"
#include "render_controller.h"
#include "settings_menu.h"

class SceneController {
private:
  std::string game_state;
  RenderController *render_controller;
  KnobsController *knobs_controller;
  DiodController *diod_controller;
  struct timespec loop_delay;

  Player *player;

  MainMenu *main_menu;
  Level *level;
  GameOverMenu *gameover_menu;
  SettingsMenu *settings_menu;

public:
  SceneController();
  std::string getGameState();
  void setGameState(std::string game_state);

  void startGame();
};
