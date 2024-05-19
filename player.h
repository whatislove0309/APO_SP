#pragma once
#include "entity.h"
#include "knobs_controller.h"

class Player:public Entity
{
private:
    KnobsController *knobs_controller;
public:
    Player();
    void draw();
    void setKnobsController(KnobsController *knobs_controller);
};
