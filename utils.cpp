#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

Image *loadImg(const char *filename) {
  FILE *file = fopen(filename, "rb");

  if (!file) {
    printf("Error reading file!\n");
    return NULL;
  }

  Image *img = (Image *)malloc(sizeof(Image));

  if (!img) {
    printf("Unexpected error!\n");
    free(img);
    return NULL;
  }

  int ret = fscanf(file, "%d %d\n", &img->width, &img->height);

  if (ret != 2) {
    printf("Unexpected error!\n");
    free(img);
    return NULL;
  }

  img->data = (unsigned short *)malloc(img->width * img->height * sizeof(unsigned short));

  fread(img->data, sizeof(unsigned short), img->width * img->height, file);

  fclose(file);
  return img;
}
