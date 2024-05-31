#pragma once

#include <cstdio>

#include "knobs_controller.h"
#include "render_controller.h"
#include "scene.h"

class GameOverMenu : public Scene {
private:
  int score = 0;

public:
  using Scene::Scene;
  GameOverMenu(RenderController *render_controller,
               KnobsController *knobs_controller);
  void draw();
  void setScore(int score);
  void drawScore();
};
