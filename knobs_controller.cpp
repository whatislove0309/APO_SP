#include "knobs_controller.h"

KnobsController::KnobsController() {
  knobs_mem_base = (unsigned char *)map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
}

void KnobsController::update() {
  if (is_stopped) {
    auto now = std::chrono::steady_clock::now();
    if (now >= stop_time) {
      is_stopped = false;
    } else {
      is_red_pressed = false;
      is_green_pressed = false;
      is_blue_pressed = false;
      return;
    }
  }

  knobs = *(knobs_t *)(knobs_mem_base + SPILED_REG_KNOBS_8BIT_o);
  is_red_pressed = knobs.is_red_pressed;
  is_green_pressed = knobs.is_green_pressed;
  is_blue_pressed = knobs.is_blue_pressed;
}

void KnobsController::disable(int seconds) {
  is_stopped = true;
  stop_time = std::chrono::steady_clock::now() + std::chrono::seconds(seconds);
}
