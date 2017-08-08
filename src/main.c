#include <stdio.h>

#include "options.h"
#include "png.h"

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

    if (isPngFile(img) != 0)
    {
	perror("No es un archivo con formato PNG.");
	return 1;
    }

    get_chunks(img);

    fclose(img);

}
