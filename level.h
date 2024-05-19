#include <iostream>
#include "render_controller.h"
#include "knobs_controller.h"
#include "scene.h"
#include "player.h"

class Level:public Scene {
protected:
    Player *player;

public:
  Level();
  void draw();
};
