#pragma once
#include <vector>
#include "entity.h"
#include "bullet.h"

class Player : public Entity {
private:
  KnobsController *knobs_controller;

public:
  using Entity::Entity;
  Player(RenderController *render_controller, KnobsController *knobs_controller);
  void draw();
};
