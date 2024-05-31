#pragma once

#include "knobs_controller.h"
#include "player.h"
#include "render_controller.h"
#include "scene.h"

class SettingsMenu : public Scene {
private:
    Player *player;
public:
  using Scene::Scene;
  SettingsMenu(RenderController *render_controller, KnobsController *knobs_controller, Player *player);
  void draw();
};
