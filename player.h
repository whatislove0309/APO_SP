#pragma once
#include <vector>
#include "entity.h"
#include "bullet.h"
#include "diod_controller.h"

class Player : public Entity {
private:
  KnobsController *knobs_controller;
  DiodController *diod_controller;
  int health;
  int maxHealth = 4;

public:
  using Entity::Entity;
  Player(RenderController *render_controller, KnobsController *knobs_controller, 
    DiodController *diod_controller);
  void draw();
  int getHealth();
  void damage();
};
