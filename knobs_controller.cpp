#include "knobs_controller.h"

KnobsController::KnobsController() {
    knobs_mem_base = (unsigned char *)map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
}

void KnobsController::update() {
  knobs = *(knobs_t *)(knobs_mem_base + SPILED_REG_KNOBS_8BIT_o);
  printf("%d %d %d\n", knobs.is_red_pressed, knobs.is_green_pressed, knobs.is_blue_pressed);
  if (knobs.is_red_pressed) {
    is_red_pressed = true;
  }
  if (knobs.is_green_pressed) {
    is_green_pressed = true;
  }
  if (knobs.is_blue_pressed) {
    is_blue_pressed = true;
  }
}
