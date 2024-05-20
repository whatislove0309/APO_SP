#include "level.h"

Level::Level(RenderController *render_controller,
             KnobsController *knobs_controller)
    : Scene::Scene(render_controller, knobs_controller) {
  player = new Player(render_controller, knobs_controller);
  setGameState("level");
}

void Level::draw() {
  render_controller->drawLevelBackground();
  if (knobs_controller->is_green_pressed) {
    createBullet(player->getX(), player->getWidth(), player->getHeight());
  }

  player->draw();
  // for (Bullet *bullet : bullets) {
  //   bullet->draw();
  // }
}

void Level::createBullet(int x, int width, int height) {
  bullets.push_back(
      new Bullet(render_controller, x + width / 2 - 10));
}
