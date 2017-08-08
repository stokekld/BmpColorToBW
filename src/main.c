#include <stdio.h>
#include <inttypes.h>

#include "options.h"

int main(int argc, char *argv[])
{
    int ret;
    uint8_t png_sing[8] = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a}, c[8];

    ret = options(argc, argv);
    if (ret != 0)
	return 1;

    FILE *img = fopen(argv[1], "rb");

    if (img == NULL)
    {
	perror("No se pudo abrir el archivo.");
	return 1;
    }

    fseek(img, 0, SEEK_SET);
    fread(&c, sizeof(uint8_t), 8, img);

    printf("%d", memcmp(png_sing, c, 8));

    fclose(img);

}
