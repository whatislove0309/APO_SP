/*******************************************************************
  Project main function template for MicroZed based MZ_APO board
  designed by Petr Porazil at PiKRON

  Project developers: Deshko Vladyslav, Fedorchuk Sofiia

 *******************************************************************/

#define _POSIX_C_SOURCE 200112L

#define WIDTH 320
#define HEIGHT 480

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib> 
#include <time.h>
#include <errno.h>

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "serialize_lock.h"
#include "utils.h"

unsigned short *fb = new unsigned short[WIDTH * HEIGHT];
unsigned char *parlcd_mem_base, *mem_base;
unsigned char *knobs_mem_base;

typedef struct Pxl {
  unsigned int r : 5;
  unsigned int g : 6; 
  unsigned int b : 5;
} pxl_t;

typedef struct {
  unsigned int blue: 8;
  unsigned int green: 8;
  unsigned int red: 8;
  unsigned int is_blue_pressed: 1;
  unsigned int is_green_pressed: 1;
  unsigned int is_red_pressed: 1;
  unsigned int trash: 5;
} knobs_t;

void draw_background(int x, int y, Image *img) {
  if (img == NULL || img->data == NULL) {
    return;
  }

  for (int i = 0; i < img->height; ++i) {
    for (int j = 0; j < img->width; ++j) {
      int board_x = x + j;
      int board_y = y + i;
      if (board_x >= 0 && board_x < WIDTH && board_y >= 0 && board_y < HEIGHT) {
        fb[board_y * WIDTH + board_x] = img->data[i * img->width + j];
      }
    }
  }
}

void highlight_region(int x, int y, int width, int height) {
  for (size_t i = 0; i < height; i++)
  {
    for (size_t j = 0; j < width; j++)
    {
      int board_x = x + j;
      int board_y = y + i;
      if (board_x >= 0 && board_x < WIDTH && board_y >= 0 && board_y < HEIGHT) {
        pxl_t* pixel = (pxl_t*)(fb + board_y * WIDTH + board_x);
        pixel->r <<= 1;
        pixel->g <<= 1;
        pixel->b <<= 1;
      }
    }
  }
  
}

int main(int argc, char *argv[]) {

  mem_base = (unsigned char *)map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
  knobs_mem_base = (unsigned char *)map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);


  if (mem_base == nullptr) {
    std::exit(1);
  }
  parlcd_hx8357_init(mem_base);

  struct timespec loop_delay = 
    {.tv_sec = 0, .tv_nsec = 30 * 1000 * 1000};

  Image *backgroundImg = loadImg("/tmp/oleksandr/assets/background.565");
  knobs_t knobs;
  while (1) {
    draw_background(1, 2, backgroundImg);

    knobs = *(knobs_t*)(knobs_mem_base + SPILED_REG_KNOBS_8BIT_o);
    printf("%d %d %d\n", knobs.is_red_pressed, knobs.is_green_pressed, knobs.is_blue_pressed);
    if(knobs.is_red_pressed) {
      highlight_region(58, 145, 142, 35);
    }
    if(knobs.is_green_pressed) {
      highlight_region(58, 192, 142, 35);
    }
    if(knobs.is_blue_pressed) {
      highlight_region(58, 240, 142, 35);
    }

    parlcd_write_cmd(mem_base, 0x2c);
    for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
      *(volatile uint16_t*)(mem_base + PARLCD_REG_DATA_o) = fb[i];
    }

    clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
  }
  delete fb;
  return 0;
}
