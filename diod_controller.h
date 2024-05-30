#pragma once

#include "stdio.h"
#include <cstdlib>
#include <cstdint>
#include <math.h>

#include "mzapo_phys.h"
#include "mzapo_regs.h"

class DiodController
{
private:
    unsigned char *diod_mem_base;
    uint32_t lcd_value;

public:
    DiodController();
    void diod(int i);
};
