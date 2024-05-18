#include <iostream>
#include <display.h>
#include <utils.h>

#ifndef RENDERCONTROLLER_H
#define RENDERCONTROLLER_H

#define WIDTH 480
#define HEIGHT 320

class RenderController {
private:
  unsigned short *fb;
  unsigned char *mem_base;

public:
  RenderController();
  void drawBackground();
  void drawImage(int x, int y, Image *image);
};

#endif
