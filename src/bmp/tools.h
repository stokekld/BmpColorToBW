#include "pixels.h"

int isBmpImage(FILE *file);
int num_null_bytes(int width);
void ctobw(Pixel **matrix, int pixels);
