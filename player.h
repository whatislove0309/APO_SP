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
  int defX = 213;
  int defY = 238;
  std::chrono::time_point<std::chrono::steady_clock> lastRecoveryTime;
  const int recoveryInterval = 20;

public:
  using Entity::Entity;
  Player(RenderController *render_controller, KnobsController *knobs_controller,
         DiodController *diod_controller);
  int getHealth();
  void draw();
  void damage();
  void recover();
  void reset();
};
