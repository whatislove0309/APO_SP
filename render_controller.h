#pragma once
#include <iostream>
#include <parlcd_controller.h>
#include <utils.h>

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
  typedef struct Pxl {
    unsigned int r : 5;
    unsigned int g : 6;
    unsigned int b : 5;
  } pxl_t;

public:
  RenderController();
  void drawMainBackground();
  void drawLevelBackground();
  void drawImage(int x, int y, Image *image);
  void drawShip(int x);
  void drawMainMenuBtns();
  void drawBullet(int x, int y);
  void reset();
  void higlightRegion(int x, int y, int width, int height);
  void update();
};

#endif
