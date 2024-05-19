#include "scene.h"

void Scene::setRenderController(RenderController *render_controller) {
  this->render_controller = render_controller;
}

void Scene::setKnobsController(KnobsController *knobs_controller) {
  this->knobs_controller = knobs_controller;
}

void Scene::setGameState(std::string game_state) {
    this->game_state = game_state;
}

std::string Scene::getGameState() { return game_state; }