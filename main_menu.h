#pragma once
#include "knobs_controller.h"
#include "render_controller.h"
#include "scene.h"

class MainMenu : public Scene {
public:
  using Scene::Scene;
  MainMenu(RenderController *render_controller,
           KnobsController *knobs_controller);
  void draw();
};
