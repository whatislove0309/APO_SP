#pragma once
#include "scene.h"
#include "render_controller.h"
#include "knobs_controller.h"

class GameOverMenu: public Scene
{
public:
    using Scene::Scene;
    GameOverMenu(RenderController *render_controller, KnobsController *knobs_controller);
    void draw();
};
