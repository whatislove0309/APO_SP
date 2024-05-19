#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MASK_SIZE 3

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    char magic[3];
    int height, width, max_val;
    Pixel *data;
} Image;

typedef struct {
    int width, height;
    unsigned short *data;
} Image565;

Image *loadImg(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (!file) {
        printf("Error reading file!\n");
        return NULL;
    }

    Image *img = (Image *) malloc(sizeof(Image));

    if (!img) {
        printf("Unexpected error!\n");
        free(img);
        return NULL;
    }

    int ret = fscanf(file, "%s\n%d %d\n%d\n", img->magic, &img->width, &img->height, &img->max_val);
    if (ret != 4) {
        printf("Unexpected error!\n");
        free(img);
        return NULL;
    }
    img->data = (Pixel *) malloc(img->width * img->height * sizeof(Pixel));

    fread(img->data, sizeof(Pixel), img->width * img->height, file);

    fclose(file);
    return img;
}

void saveImg(const char *filename, Image565 *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file!\n");
        return;
    }

    fprintf(file, "%d %d\n", img->width, img->height);
    fwrite(img->data, sizeof(unsigned short), img->width * img->height, file);

    fclose(file);
}

void freeImage(Image *img) {
    free(img->data);
    free(img);
}

unsigned short rgbToRgb565(Pixel *pixel) {
    unsigned short color = (pixel->r >> 3) << 11 | (pixel->g >> 2) << 5 | (pixel->b >> 3);
    printf("%hu\n", color);
    return color;
}

Image565 *processImage(Image *img) {
    Image565 *output = (Image565*)malloc(sizeof(Image565));
    if (!output) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    output->width = img->width;
    output->height = img->height;
    output->data = (unsigned short*)malloc(output->width * output->height * sizeof(unsigned short));

    if (!output->data) {
        printf("Memory allocation failed\n");
        return NULL;
    }
   
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            unsigned short color = rgbToRgb565(&(img->data[i * img->width + j]));
            output->data[i * img->width + j] = color;
        }
    }
    return output;
}

void print565(Image565 *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        // printf("%hu\t", img->data[i]);
        if (!((i+1) % img->width)) {
            // printf("\n");
        }
    }
}

Image565 *readFrom565(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (!file) {
        printf("Error reading file!\n");
        return NULL;
    }

    Image565 *img = (Image565*) malloc(sizeof(Image565));

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


    img->data = (unsigned short*)malloc(img->width * img->height * sizeof(unsigned short));

    fread(img->data, sizeof(unsigned short), img->width * img->height, file);

    fclose(file);
    return img;
}

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("Invalid usage!\n");
        return 1;
    }

    // load input img
    Image *inputImage = loadImg(argv[1]);

    if (!inputImage) {
        free(inputImage);
        printf("Unexpected error!\n");
        return 1;
    }

    printf("Loading image\n");
    Image565 *output = processImage(inputImage);
    print565(output);

    saveImg("background.565", output);

    freeImage(inputImage);

    return 0;
}