#pragma once
#include <vector>
#include "entity.h"
#include "asteroid.h"
#include "bullet.h"
#include "player.h"
#include "level.h"

class CollisionController
{
private:
    Level* level; 
public:
    CollisionController(Level* level) : level(level) {};
    bool checkCollision(Entity *entity_1, Entity *entity_2);
    void checkBulletCollision(std::vector<Bullet *>* bullets, std::vector<Asteroid *>* asteroids);
    void checkPlayerCollsion(Player *player, std::vector<Asteroid *>* asteroids);
};
