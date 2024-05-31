#pragma once
#include <chrono>

#include "bullet.h"
#include "diod_controller.h"
#include "entity.h"
#include "utils.h"

class Player : public Entity {
private:
  KnobsController *knobs_controller;
  DiodController *diod_controller;

  Image *ship_1;
  Image *ship_2;
  Image *ship_3;
  Image *active_ship;

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
  void setSkin(int index);
};
