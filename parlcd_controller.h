#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include <cstdlib>

class ParLCDController {
private:
  unsigned char *mem_base, *knobs_mem_base;

public:
  ParLCDController();
  unsigned char *getMemBase();
};
