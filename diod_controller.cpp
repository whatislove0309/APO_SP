#include "diod_controller.h"

DiodController::DiodController() {
  diod_mem_base = (unsigned char *)map_phys_address(SPILED_REG_LED_LINE_o, SPILED_REG_SIZE, 0);
  if (diod_mem_base == nullptr) {
    std::exit(1);
  }

  
//   spil(mem_base);
}