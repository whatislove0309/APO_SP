#include "render_controller.h"

RenderController::RenderController() {
  ParLCDController parlcd_controller = ParLCDController();
  mem_base = parlcd_controller.getMemBase();
  fb = new unsigned short[WIDTH * HEIGHT];

  backgroundImage = loadImg("/tmp/deshkvla/assets/background.565");
  levelBackgroundImage = loadImg("/tmp/deshkvla/assets/background_level.565");
  gameOverBackgroundImage = loadImg("/tmp/deshkvla/assets/background_gameover.565");
  ship_1 = loadImg("/tmp/deshkvla/assets/ship_1.565");
  asteroid = loadImg("/tmp/deshkvla/assets/asteroid.565");

  fdes = &font_rom8x16;
}

void RenderController::update() {
  parlcd_write_cmd(mem_base, 0x2c);
  for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
    *(volatile uint16_t *)(mem_base + PARLCD_REG_DATA_o) = fb[i];
  }
}

void RenderController::reset() { 
  fb = new unsigned short[WIDTH * HEIGHT]; 
}

void RenderController::drawMainBackground() {
  drawImage(0, 0, backgroundImage);
}

void RenderController::drawLevelBackground() {
  drawImage(0, 0, levelBackgroundImage);
}

void RenderController::drawGameOverBackground() {
  drawImage(0, 0, gameOverBackgroundImage);
}

void RenderController::drawImage(int x, int y, Image *img) {
  if (img == NULL || img->data == NULL) {
    return;
  }

  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      int board_x = x + j;
      int board_y = y + i;

      if (board_x >= 0 && board_x < WIDTH && board_y >= 0 && board_y < HEIGHT) {
        uint16_t color = img->data[i * img->width + j];

        if (color != 0xFFE0) {
          fb[board_y * WIDTH + board_x] = color;
        }
      }
    }
  }
}

void RenderController::higlightRegion(int x, int y, int width, int height) {
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      int board_x = x + j;
      int board_y = y + i;
      if (board_x >= 0 && board_x < WIDTH && board_y >= 0 && board_y < HEIGHT) {
        pxl_t *pixel = (pxl_t *)(fb + board_y * WIDTH + board_x);
        pixel->r <<= 1;
        pixel->g <<= 1;
        pixel->b <<= 1;
      }
    }
  }
}

void RenderController::drawShip(int x) { 
  drawImage(x, 248, ship_1); 
}

void RenderController::drawAsteroid(int x, int y) { 
  drawImage(x, y, asteroid); 
}

void RenderController::drawBullet(int x, int y, int width, int height) {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      int drawY = y + j;
      int drawX = x + i;
      fb[drawY * WIDTH + drawX] = 0xffff;
    }
  }
}

void RenderController::drawText(int x, int y, const char *text, uint16_t color, int scale) {
  while (*text) {
    drawChar(x, y, *text, color, scale);
    x += (charWidth(*text) + 20);
    text++;
  }
}

void RenderController::drawChar(int x, int y, char ch, uint16_t color, int scale) {
  int w = charWidth(ch);
  const font_bits_t *ptr;

  if ((ch >= fdes->firstchar) && (ch - fdes->firstchar < fdes->size)) {
    if (fdes->offset) {
      ptr = &fdes->bits[fdes->offset[ch - fdes->firstchar]];
    } else {
      int bw = (fdes->maxwidth + 15) / 16;
      ptr = &fdes->bits[(ch - fdes->firstchar) * bw * fdes->height];
    }
    for (int i = 0; i < fdes->height; i++) {
      font_bits_t val = *ptr;
      for (int j = 0; j < w; j++) {
        if ((val & 0x8000) != 0) {
          drawPixel(x + scale * j, y + scale * i, color, scale);
        }
        val <<= 1;
      }
      ptr++;
    }
  }
}

int RenderController::charWidth(int ch) {
  if (ch < fdes->firstchar || ch > fdes->firstchar + fdes->size) {
    ch = fdes->defaultchar;
  }

  int width;
  if (!fdes->width) {
    width = fdes->maxwidth;
  } else {
    width = fdes->width[ch - fdes->firstchar];
  }
  return width;
}

int RenderController::wordWidth(const char *text) {
  int totalWidth = 0;

  while (*text) {
    totalWidth += charWidth(*text);
    text++;
  }

  return totalWidth;
}

void RenderController::drawPixel(int x, int y, uint16_t color, int scale) {
  for (int i = 0; i < scale; i++) {
    for (int j = 0; j < scale; j++) {
      if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        for (int k = 0; k < 5; k++) {
          fb[x + k + WIDTH * y] = color;
        }
      }
    }
  }
}
