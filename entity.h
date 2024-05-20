#pragma once
#include "render_controller.h"
#include "knobs_controller.h"

class Entity
{
protected:
    int x, y, width, height, speed;
    RenderController *render_controller;
public:
    Entity(){};
    Entity(RenderController *render_controller, int x, int y, int width, int height);
    virtual void draw(int x, int y){};
    void setPosition(int x, int y);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
};
