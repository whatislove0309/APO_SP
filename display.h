#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "mzapo_parlcd.h"
#include <cstdlib> 

class ParLCD
{
private:
    unsigned char *mem_base;
public:
    ParLCD();
    unsigned char* getMemBase();
};
