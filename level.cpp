#include "level.h"

Level::Level(RenderController *render_controller,
             KnobsController *knobs_controller)
    : Scene::Scene(render_controller, knobs_controller)
{
  player = new Player(render_controller, knobs_controller);
  setGameState("level");
}

void Level::draw()
{
  render_controller->drawLevelBackground();

  render_controller->drawAsteroid(0, 0);

  auto now = std::chrono::steady_clock::now();
  if (knobs_controller->is_green_pressed && (now - last_bullet_time) > bullet_delay)
  {
    createBullet(player->getX() + player->getWidth()/2 - 10);
    createBullet(player->getX() + player->getWidth()/2 + 15);
    last_bullet_time = now;
  }

  player->draw();
  drawBullets();
  printf("%d\n", bullets.size());
}

void Level::createBullet(int x)
{
  for (Bullet *bullet : bullets)
  {
    if (bullet->getIsOut())
    {
      bullet->reset(x);
      return;
    }
  }

  bullets.push_back(
      new Bullet(render_controller, x));
}

void Level::drawBullets()
{
  for (Bullet *bullet : bullets)
  {
    if (!bullet->getIsOut())
    {
      bullet->draw();
    }
  }
}
