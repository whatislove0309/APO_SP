#pragma once
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include "asteroid.h"
#include "render_controller.h"

class AsteroidController
{
private:
    RenderController *render_controller;
    std::vector<Asteroid *> asteroids;
    std::chrono::steady_clock::time_point last_time;
    const std::chrono::duration<double> bullet_delay = std::chrono::duration<double>(1);

public:
    AsteroidController(RenderController *render_controller);
    void generateAsteroids();
    std::vector<Asteroid *> asteroidsList();
    void draw();
    int getRandomX();
};
