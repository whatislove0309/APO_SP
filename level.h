#pragma once
#include "knobs_controller.h"
#include "player.h"
#include "render_controller.h"
#include "scene.h"
#include <iostream>
#include <chrono>
#include <thread>

class Level : public Scene {
protected:
  Player *player;
  std::vector<Bullet*> bullets;
  std::chrono::steady_clock::time_point last_bullet_time;
  const std::chrono::duration<double> bullet_delay = std::chrono::duration<double>(0.2);


public:
  using Scene::Scene;
  Level(RenderController *render_controller, KnobsController *knobs_controller);
  void draw();
  void createBullet(int x);
  void drawBullets();
};
