#include "level.h"

Level::Level(RenderController *render_controller,
             KnobsController *knobs_controller)
    : Scene::Scene(render_controller, knobs_controller)
{
  player = new Player(render_controller, knobs_controller);
  asteroid_controller = new AsteroidController(render_controller);
  bullet_controller = new BulletController(render_controller);
  collision_controller = new CollisionController();
  setGameState("level");
}

void Level::draw()
{
  render_controller->drawLevelBackground();
  asteroid_controller->generateAsteroids();

  if (knobs_controller->is_green_pressed)
  {
    int x1 = player->getX() + player->getWidth()/2 - 10;
    int x2 = player->getX() + player->getWidth()/2 + 16;
    bullet_controller->shoot(x1, x2, player->getY());
  }
  
  
  collision_controller->checkBulletCollision(bullet_controller->bulletsList(), asteroid_controller->asteroidsList());

  player->draw();
  asteroid_controller->draw();
  bullet_controller->draw();
}


