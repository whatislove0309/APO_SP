#pragma once
#include "asteroid.h"
#include "bullet.h"
#include "entity.h"
#include "player.h"
#include <vector>

class CollisionController {
public:
  bool checkCollision(Entity *entity_1, Entity *entity_2);
  void checkBulletCollision(std::vector<Bullet *> *bullets,
                            std::vector<Asteroid *> *asteroids);
  void checkPlayerCollsion(Player *player, std::vector<Asteroid *> *asteroids);
};
