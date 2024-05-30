#include "render_controller.h"

RenderController::RenderController() {
  ParLCDController parlcd_controller = ParLCDController();
  mem_base = parlcd_controller.getMemBase();
  fb = new unsigned short[WIDTH * HEIGHT];

  backgroundImage = loadImg("/tmp/deshkvla/assets/background.565");
  levelBackgroundImage = loadImg("/tmp/deshkvla/assets/background_level.565");
  gameOverBackgroundImage =
      loadImg("/tmp/deshkvla/assets/background_gameover.565");
  ship_1 = loadImg("/tmp/deshkvla/assets/ship_1.565");
  asteroid = loadImg("/tmp/deshkvla/assets/asteroid.565");
}

void RenderController::update() {
  parlcd_write_cmd(mem_base, 0x2c);
  for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
    *(volatile uint16_t *)(mem_base + PARLCD_REG_DATA_o) = fb[i];
  }
}

void RenderController::reset() { fb = new unsigned short[WIDTH * HEIGHT]; }

void RenderController::drawMainBackground() {
  drawImage(0, 0, backgroundImage);
}

void RenderController::drawLevelBackground() {
  drawImage(0, 0, levelBackgroundImage);
}

void RenderController::drawGameOverBackground() {
  drawImage(0, 0, gameOverBackgroundImage);
}

uint16_t invertRGB565(uint16_t pixel) {
  uint16_t red = (pixel >> 11) & 0x1F;
  uint16_t green = (pixel >> 5) & 0x3F;
  uint16_t blue = pixel & 0x1F;

  uint16_t red_inverted = 0x1F - red;
  uint16_t green_inverted = 0x3F - green;
  uint16_t blue_inverted = 0x1F - blue;

  return (red_inverted << 11) | (green_inverted << 5) | blue_inverted;
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
          // uint16_t invertedColor = invertRGB565(color);
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

void RenderController::drawShip(int x) { drawImage(x, 248, ship_1); }

void RenderController::drawAsteroid(int x, int y) { drawImage(x, y, asteroid); }

void RenderController::drawBullet(int x, int y, int width, int height) {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      int drawY = y + j;
      int drawX = x + i;
      fb[drawY * WIDTH + drawX] = 0xffff;
    }
  }
}

void RenderController::drawChar(int x, int y, char c,
                                const font_descriptor_t *font, uint16_t color) {
  if (c < font->firstchar || c >= font->firstchar + font->size) {
    c = font->defaultchar;
  }

  int index = c - font->firstchar;
  const font_bits_t *charBits = font->bits + font->offset[index];
  int charWidth = font->width ? font->width[index] : font->maxwidth;

  for (int i = 0; i < font->height; i++) {
    font_bits_t bits = charBits[i];
    for (int j = 0; j < charWidth; j++) {
      if (bits & (1 << (font->maxwidth - 1 - j))) {
        int drawX = x + j;
        int drawY = y + i;
        if (drawX >= 0 && drawX < WIDTH && drawY >= 0 && drawY < HEIGHT) {
          fb[drawY * WIDTH + drawX] = color;
        }
      }
    }
  }
}

void RenderController::drawText(int x, int y, const char *text,
                                const font_descriptor_t *font, uint16_t color) {
  while (*text) {
    drawChar(x, y, *text, font, color);
    x += font->width ? font->width[*text - font->firstchar] : font->maxwidth;
    text++;
  }
}
