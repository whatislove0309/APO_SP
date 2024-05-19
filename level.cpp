#include "level.h"

Level::Level() { setGameState("level"); }

void Level::draw() {
  render_controller->drawLevelBackground();

  
}
