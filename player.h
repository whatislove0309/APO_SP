#pragma once
#include <vector>
#include <chrono>

#include "bullet.h"
#include "diod_controller.h"
#include "entity.h"

class Player : public Entity {
private:
  KnobsController *knobs_controller;
  DiodController *diod_controller;
  int health;
  int maxHealth = 4;
  std::chrono::time_point<std::chrono::steady_clock> lastRecoveryTime;
  const int recoveryInterval = 15;

public:
  using Entity::Entity;
  Player(RenderController *render_controller, KnobsController *knobs_controller,
         DiodController *diod_controller);
  void draw();
  int getHealth();
  void damage();
  void recover();
};
