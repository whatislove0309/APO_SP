#pragma once
#include "entity.h"
#include "knobs_controller.h"

class Player : public Entity {
private:
  KnobsController *knobs_controller;

public:
  using Entity::Entity;
  Player(RenderController *render_controller, int x, int y, int width,
         int height, int speed, KnobsController *knobs_controller);
  void draw();
};
