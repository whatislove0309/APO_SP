#include "collision_controller.h"

CollisionController::CollisionController(std::function<void()> callback) {
  this->updateScoreCallback = callback;
}

bool CollisionController::checkCollision(Entity *entity_1, Entity *entity_2) {
  if (entity_1->getX() + entity_1->getWidth() < entity_2->getX() ||
      entity_2->getX() + entity_2->getWidth() < entity_1->getX())
    return false;

  if (entity_1->getY() + entity_1->getHeight() < entity_2->getY() ||
      entity_2->getY() + entity_2->getHeight() < entity_1->getY())
    return false;

  return true;
}

void CollisionController::checkBulletCollision(
    std::vector<Bullet *> *bullets, std::vector<Asteroid *> *asteroids) {
  for (Asteroid *asteroid : *asteroids) {
    if (asteroid->getIsOut())
      continue;

    for (Bullet *bullet : *bullets) {
      if (bullet->getIsOut())
        continue;

      if (checkCollision(bullet, asteroid)) {
        bullet->destroy();
        asteroid->destroy();
        if (updateScoreCallback) {
          updateScoreCallback();
        }
      }
    }
  }
}

void CollisionController::checkPlayerCollsion(
    Player *player, std::vector<Asteroid *> *asteroids) {
  for (Asteroid *asteroid : *asteroids) {
    if (asteroid->getIsOut())
      continue;

    if (checkCollision(player, asteroid)) {
      asteroid->destroy();
      player->damage();
    }
  }
}
