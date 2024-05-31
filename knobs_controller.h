#pragma once

#include "stdio.h"
#include <chrono>

#include "mzapo_phys.h"
#include "mzapo_regs.h"

class KnobsController {
private:
  unsigned char *knobs_mem_base;

  typedef struct {
    unsigned int blue : 8;
    unsigned int green : 8;
    unsigned int red : 8;
    unsigned int is_blue_pressed : 1;
    unsigned int is_green_pressed : 1;
    unsigned int is_red_pressed : 1;
    unsigned int trash : 5;
  } knobs_t;

  knobs_t knobs;
  bool is_stopped = false;
  std::chrono::steady_clock::time_point stop_time;

public:
  KnobsController();
  bool is_red_pressed, is_green_pressed, is_blue_pressed;
  void update();
  void disable(int seconds);
};
