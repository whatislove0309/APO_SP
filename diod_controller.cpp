#include "diod_controller.h"

DiodController::DiodController() {
  diod_mem_base = (unsigned char *)map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
  if (diod_mem_base == nullptr) {
    std::exit(1);
  }
}

void DiodController::diod() {
  *(volatile uint32_t*)(diod_mem_base + SPILED_REG_LED_LINE_o) = 4294967295;
}
