#pragma once
#include "knobs_controller.h"
#include "player.h"
#include "render_controller.h"
#include "scene.h"
#include <iostream>

class Level : public Scene {
protected:
  Player *player;

public:
  using Scene::Scene;
  Level(RenderController *render_controller, KnobsController *knobs_controller);
  void draw();
};
