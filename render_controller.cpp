#include "render_controller.h"

RenderController::RenderController() {
  ParLCD parLCD = ParLCD();
  mem_base = parLCD.getMemBase();
  fb = new unsigned short[WIDTH * HEIGHT];
}

void RenderController::drawBackground() {
  Image *backgroundImg = loadImg("/tmp/oleksandr/assets/background.565");

  drawImage(0, 0, backgroundImg);

  parlcd_write_cmd(mem_base, 0x2c);
  for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
    *(volatile uint16_t *)(mem_base + PARLCD_REG_DATA_o) = fb[i];
  }
}

void RenderController::drawImage(int x, int y, Image *img) {
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
