#pragma once
#include "knobs_controller.h"
#include "player.h"
#include "render_controller.h"
#include "scene.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "asteroid_controller.h"
#include "bullet_controller.h"
#include "collision_controller.h"
#include "diod_controller.h"

class Level : public Scene {
protected:
  Player *player;
  AsteroidController *asteroid_controller;
  BulletController *bullet_controller;
  CollisionController *collision_controller;
  DiodController *diod_controller;

public:
  using Scene::Scene;
  Level(RenderController *render_controller, KnobsController *knobs_controller, DiodController *diod_controller);
  void draw();
};
