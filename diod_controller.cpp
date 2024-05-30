#include "diod_controller.h"

DiodController::DiodController() {
  diod_mem_base = (unsigned char *)map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
  if (diod_mem_base == nullptr) {
    std::exit(1);
  }
  *(volatile uint32_t*)(diod_mem_base + SPILED_REG_LED_LINE_o) = 0;
  lcd_value = 0;
}

void DiodController::diod(int i) {
  uint32_t value = (1 << (8 * i)) -1;
  value <<= (32 - 8 * i);
  *(volatile uint32_t*)(diod_mem_base + SPILED_REG_LED_LINE_o) = value;
}
