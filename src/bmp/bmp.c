#include <stdlib.h>

#include "bmp.h"
#include "headers.h"
#include "tools.h"
#include "output.h"

// funcion principal
int bmp(FILE *file)
{
    int nullbts;
    BMPHeader header;
    IHeader iheader;
    Pixel *matrix, *output;

    // Verificando que sea una imagen bmp
    if (isBmpImage(file) != 0)
    {
	perror("No es un archivo con formato BMP.");
	return 1;
    }

    get_header(&header, file);

    printf("Tamaño de imagen (bytes):\t%d\n", header.size);

    get_iHeader(&iheader, file);

    printf("Ancho de imagen (px):\t\t%d\n", iheader.width);
    printf("Alto de imagen (px):\t\t%d\n", iheader.height);
    printf("Bits por px:\t\t\t%d\n", iheader.count);

    if (iheader.count != 24)
    {
	perror("Este comando solo funciona con imagenes de 24 bits por px.");
    }

    // Obtencion de bytes null por fila
    nullbts = num_null_bytes(iheader.width);

    // Dando espacio a la matriz
    matrix = malloc(sizeof(Pixel) * iheader.width * iheader.height);
    output = malloc(sizeof(Pixel) * iheader.width * iheader.height);

    // Obtencion de matriz de pixele	// Obtencion de matriz de pixeless
    get_matrix(matrix, file, iheader.height, iheader.width, nullbts);

    // Convirtiendo a blanco y negro
    ctobw(&matrix, iheader.height, iheader.width);
    rotate(&output, matrix, 180, iheader.height, iheader.width);

    // Mandando datos al archivo
    dumb_file(&header, &iheader, output, iheader.height, iheader.width, nullbts);

    /*free(matrix);*/

}
