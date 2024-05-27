#pragma once
#include <vector>
#include "entity.h"
#include "asteroid.h"
#include "bullet.h"
#include "player.h"

class CollisionController
{
private:
    
public:
    bool checkCollision(Entity *entity_1, Entity *entity_2);
    void checkBulletCollision(std::vector<Bullet *>* bullets, std::vector<Asteroid *>* asteroids);
    void checkPlayerCollsion(Player *player, std::vector<Asteroid *>* asteroids);
};
