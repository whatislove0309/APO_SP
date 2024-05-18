/*******************************************************************
  Project main function template for MicroZed based MZ_APO board
  designed by Petr Porazil at PiKRON

  Project developers: Deshko Vladyslav, Fedorchuk Sofiia

 *******************************************************************/

#define _POSIX_C_SOURCE 200112L

#define WIDTH 320
#define HEIGHT 480

#include <cstdlib>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "render_controller.h"
#include "knobs_controller.h"
#include "serialize_lock.h"
#include "utils.h"

int main(int argc, char *argv[]) {

  struct timespec loop_delay = {.tv_sec = 0, .tv_nsec = 30 * 1000 * 1000};
  RenderController renderController = RenderController();
  KnobsController knobsController = KnobsController();

  while (1) {
    renderController.drawBackground();

    if (knobsController.is_red_pressed) {
      renderController.higlightRegion(58, 145, 142, 35);
    }
    if (knobsController.is_green_pressed) {
      renderController.higlightRegion(58, 192, 142, 35);
    }
    if (knobsController.is_blue_pressed) {
      renderController.higlightRegion(58, 240, 142, 35);
    }

    knobsController.update();
    renderController.update();

    clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
  }
  return 0;
}
