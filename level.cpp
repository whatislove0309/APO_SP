#include "level.h"

Level::Level(RenderController *render_controller, KnobsController *knobs_controller):Scene::Scene(render_controller, knobs_controller) { 
    player = new Player(render_controller, knobs_controller);
    setGameState("level"); 
}

void Level::draw() {
  render_controller->drawLevelBackground();
  player->draw();
}
