#include "pixels.h"

int isBmpImage(FILE *file);
int num_null_bytes(int width);
void ctobw(Pixel **matrix, int height, int width);;
void rotate(Pixel **output, Pixel *matrix, int degrees, int height, int width);
