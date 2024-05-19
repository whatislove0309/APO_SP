#include "level.h"

Level::Level() { 
    player = new Player(213, 238, 54, 62);
    player->setKnobsController(knobs_controller);
    player->setRenderController(render_controller);
    setGameState("level"); 
}

void Level::draw() {
  render_controller->drawLevelBackground();
  player->draw();
}
