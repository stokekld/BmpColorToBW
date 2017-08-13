#include <stdio.h>
#include <time.h>

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

    // Aplicando 
    // Tamando el tiempo
    clock_t begin = clock();

    ret = bmp(img);

    clock_t end = clock();
    if (ret != 0)
	return 1;

    fclose(img);


    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion (s):\t%f\n", time_spent);
}
