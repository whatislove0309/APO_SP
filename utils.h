#pragma once

typedef struct {
  int width, height;
  unsigned short *data;
} Image;

Image *loadImg(const char *filename);
