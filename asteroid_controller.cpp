#include "asteroid_controller.h"

AsteroidController::AsteroidController(RenderController *render_controller)
{
    this->render_controller = render_controller;
}

void AsteroidController::generateAsteroids()
{
    auto now = std::chrono::steady_clock::now();
    if ((now - last_time) > bullet_delay)
    {
        asteroids.push_back(new Asteroid(render_controller, getRandomX()));
        last_time = now;
    }
}

void AsteroidController::draw()
{
    for (Asteroid *asteroid : asteroids)
    {
        if (!asteroid->getIsOut())
        {
            asteroid->draw();
        }
    }
}

int AsteroidController::getRandomX()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 480);

    return dis(gen);
}

std::vector<Asteroid *>* AsteroidController::asteroidsList()
{
    return &asteroids;
}

void AsteroidController::reset() {
    for (Asteroid *asteroid : asteroids) {
        asteroid->destroy();
    }
}
