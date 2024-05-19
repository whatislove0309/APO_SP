#pragma once
#include "scene.h"
#include "render_controller.h"
#include "knobs_controller.h"

class MainMenu:public Scene
{
public:
    using Scene::Scene;
    MainMenu(RenderController *render_controller, KnobsController *knobs_controller);
    void draw();
};
