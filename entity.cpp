#include "entity.h"

Entity::Entity(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Entity::setRenderController(RenderController *render_controller) {
    this->render_controller = render_controller;
}
