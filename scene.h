#pragma once
#include "knobs_controller.h"
#include "render_controller.h"

class Scene {
protected:
  RenderController *render_controller;
  KnobsController *knobs_controller;

  std::string game_state;

public:
  Scene(RenderController *render_controller, KnobsController *knobs_controller);
  virtual void draw(){};
  void setGameState(std::string game_state);
  std::string getGameState();
};
