#pragma once
#include <iostream>
#include <math.h>
#include <utils.h>

#include "font_types.h"
#include "parlcd_controller.h"

#ifndef RENDERCONTROLLER_H
#define RENDERCONTROLLER_H

#define WIDTH 480
#define HEIGHT 320

class RenderController {
private:
  unsigned short *fb;
  unsigned char *mem_base;
  Image *backgroundImage;
  Image *levelBackgroundImage;
  Image *asteroid;
  Image *gameOverBackgroundImage;

  font_descriptor_t *fdes;

  typedef struct Pxl {
    unsigned int r : 5;
    unsigned int g : 6;
    unsigned int b : 5;
  } pxl_t;

public:
  RenderController();
  void reset();
  void update();
  void drawMainBackground();
  void drawLevelBackground();
  void drawGameOverBackground();
  void drawImage(int x, int y, Image *image);
  void drawShip(int x, Image *image);
  void drawBullet(int x, int y, int width, int height);
  void drawAsteroid(int x, int y);
  void higlightRegion(int x, int y, int width, int height);
  void drawChar(int x, int y, char ch, uint16_t color, int scale);
  int charWidth(int ch);
  int wordWidth(const char *text);
  void drawPixel(int x, int y, uint16_t color, int scale);
  void drawText(int x, int y, const char *text, uint16_t color, int scale);
};

#endif
