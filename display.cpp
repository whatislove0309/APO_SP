#include "display.h"

ParLCD::ParLCD() {
  mem_base = (unsigned char *)map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
  if (mem_base == nullptr) {
    std::exit(1);
  }
  parlcd_hx8357_init(mem_base);
}

unsigned char* ParLCD::getMemBase() {
    return mem_base;
}