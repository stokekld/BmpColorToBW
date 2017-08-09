#include <stdio.h>

#include "options.h"
#include "bmp.h"

int main(int argc, char *argv[])
{
    int ret;

    // Verificando opciones del comando
    ret = options(argc, argv);
    if (ret != 0)
	return 1;

    // Abriendo imagen
    FILE *img = fopen(argv[1], "rb");

    if (img == NULL)
    {
	perror("No se pudo abrir el archivo.");
	return 1;
    }

    // Verificando que sea una imagen bmp
    if (isBmpImage(img) != 0)
    {
	perror("No es un archivo con formato BMP.");
	return 1;
    }

    // Aplicando 
    ret = bmp(img);

    fclose(img);

}
