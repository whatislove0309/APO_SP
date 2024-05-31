#pragma once
#include <vector>
#include <chrono>
#include <thread>
#include "render_controller.h"
#include "bullet.h"

class BulletController
{
private:
    RenderController *render_controller;
    std::vector<Bullet *> bullets;
    std::chrono::steady_clock::time_point last_time;
    const std::chrono::duration<double> bullet_delay = std::chrono::duration<double>(0.7);
public:
    BulletController(RenderController *render_controller);
    std::vector<Bullet *>* bulletsList();
    void draw();
    void createBullet(int x, int y);
    void shoot(int x1, int x2, int y);
    void reset();
};
