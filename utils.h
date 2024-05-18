#pragma once

typedef struct {
    int width, height;
    unsigned short *data;
} Image;


// Load rgb565 image
Image *loadImg(const char *filename);
