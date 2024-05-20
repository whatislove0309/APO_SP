#include "entity.h"

Entity::Entity(RenderController *render_controller, int x, int y, int width, int height) {
    this->render_controller = render_controller;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

int Entity::getX() {
    return x;
}

int Entity::getY() {
    return y;
}

int Entity::getWidth() {
    return width;
}

int Entity::getHeight() {
    return height;
}
