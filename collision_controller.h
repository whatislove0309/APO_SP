#pragma once
#include <functional>
#include <vector>

#include "asteroid.h"
#include "bullet.h"
#include "entity.h"
#include "player.h"

class CollisionController {
private:
  std::function<void()> updateScoreCallback;

public:
  CollisionController(std::function<void()> callback);
  bool checkCollision(Entity *entity_1, Entity *entity_2);
  void checkBulletCollision(std::vector<Bullet *> *bullets,
                            std::vector<Asteroid *> *asteroids);
  void checkPlayerCollsion(Player *player, std::vector<Asteroid *> *asteroids);
};
