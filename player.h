#pragma once
#include "entity.h"
#include "knobs_controller.h"

class Player:public Entity
{
private:
    KnobsController *knobs_controller;
public:
    using Entity::Entity;
    Player(int x, int y, int width, int height, int speed);
    void draw();
    void setKnobsController(KnobsController *knobs_controller);
};
