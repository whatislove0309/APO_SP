#pragma once
#include <iostream>
#include <utils.h>
#include <math.h>

#include "parlcd_controller.h"
#include "font_types.h"

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
  Image *ship_1;
  Image *asteroid;
  Image *gameOverBackgroundImage;
  
  typedef struct Pxl {
    unsigned int r : 5;
    unsigned int g : 6;
    unsigned int b : 5;
  } pxl_t;

  void drawImage(int x, int y, Image *img);
  void drawChar(int x, int y, char c, const font_descriptor_t* font, uint16_t color);

public:
  RenderController();
  void reset();
  void update();
  void drawMainBackground();
  void drawLevelBackground();
  void drawGameOverBackground();
  void drawImage(int x, int y, Image *image);
  void drawShip(int x);
  void drawBullet(int x, int y, int width, int height);
  void drawAsteroid(int x, int y);
  void higlightRegion(int x, int y, int width, int height);
  void drawText(int x, int y, const char* text, const font_descriptor_t* font, uint16_t color);
};

#endif
