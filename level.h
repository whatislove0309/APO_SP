#include "render_controller.h"
#include <iostream>

class Level {
private:
  RenderController render_controller;
  std::string game_state;
  int playerX = 0;
  std::string direction = "left";

public:
  Level();
  void draw();
  void setRenderController(RenderController *render_controller);
  std::string getGameState();
};
