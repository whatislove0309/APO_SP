#include <iostream>
#include "render_controller.h"
#include "knobs_controller.h"
#include "scene.h"

class Level:public Scene {
private:
  int playerX = 0;

public:
  Level();
  void draw();
};
