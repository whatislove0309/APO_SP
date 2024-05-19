#pragma once
#include "render_controller.h"

class Entity
{
protected:
    int x, y, width, height, speed;
    RenderController *render_controller;
public:
    Entity();
    Entity(int x, int y, int width, int height);
    void setRenderController(RenderController *render_controller);
    virtual void draw(int x, int y);
};
