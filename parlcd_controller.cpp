#include "parlcd_controller.h"

ParLCDController::ParLCDController() {
  mem_base = (unsigned char *)map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
  knobs_mem_base = (unsigned char *)map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
  
  if (mem_base == nullptr) {
    std::exit(1);
  }
  parlcd_hx8357_init(mem_base);
}

unsigned char* ParLCDController::getMemBase() {
  return mem_base;
}