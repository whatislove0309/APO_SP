#include "scene.h"

Scene::Scene(RenderController *render_controller, KnobsController *knobs_controller) {
    this->render_controller = render_controller;
    this->knobs_controller = knobs_controller;
}

void Scene::setGameState(std::string game_state) {
    this->game_state = game_state;
}

std::string Scene::getGameState() { return game_state; }