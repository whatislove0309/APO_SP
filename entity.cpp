#include "entity.h"

Entity::Entity(RenderController *render_controller, int x, int y, int width, int height) {
    this->render_controller = render_controller;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}
