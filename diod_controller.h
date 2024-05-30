#pragma once

#include "stdio.h"
#include <cstdlib>

#include "mzapo_phys.h"
#include "mzapo_regs.h"

class DiodController
{
private:
    unsigned char *diod_mem_base;
public:
    DiodController();
    void diod();
};
