#include "level.h"

Level::Level() { setGameState("level"); }

void Level::draw() {
  render_controller.drawLevelBackground();

  if (knobs_controller.is_red_pressed) {
    if (playerX < 450) {
      playerX += 3;
    }
  }
  if (knobs_controller.is_blue_pressed) {
    if (playerX > 0) {
      playerX -= 3;
    }
  }

  render_controller.renderShip(playerX);
}
