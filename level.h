#include <iostream>
#include "render_controller.h"
#include "knobs_controller.h"

class Level {
private:
  RenderController render_controller;
  KnobsController knobs_controller;

  std::string game_state;
  int playerX = 0;

public:
  Level();
  void draw();
  void setRenderController(RenderController *render_controller);
  void setKnobsController(KnobsController *knobs_controller);
  std::string getGameState();
};
