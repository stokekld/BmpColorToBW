#include "png.h"

uint8_t png_sign[8] = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a};

int isPngFile(FILE *file)
{
    uint8_t sign[8];

    fseek(file, 0, SEEK_SET);

    fread(&sign, sizeof(uint8_t), 8, file);

    if (memcmp(png_sign, sign, 8) != 0)
	return 1;

    return 0;
}
