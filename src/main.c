#include <stdio.h>

#include "options.h"
#include "bmp.h"

int main(int argc, char *argv[])
{
    int ret;

    ret = options(argc, argv);
    if (ret != 0)
	return 1;

    FILE *img = fopen(argv[1], "rb");

    if (img == NULL)
    {
	perror("No se pudo abrir el archivo.");
	return 1;
    }

    if (isBmpImage(img) != 0)
    {
	perror("No es un archivo con formato BMP.");
	return 1;
    }

    ret = bmp(img);

    fclose(img);

}
