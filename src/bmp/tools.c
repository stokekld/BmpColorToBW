#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>
#include <omp.h>

#include "tools.h"

uint8_t bmp_sign[2] = {0x42, 0x4d};

// Funcion para verificar que es una archivo bmp
int isBmpImage(FILE *file)
{
    uint8_t sign[2];

    fseek(file, 0, SEEK_SET);
    fread(sign, sizeof(uint8_t), 2, file);

    if (memcmp(bmp_sign, sign, 2) != 0)
	return 1;

    return 0;
}

// Obtencion de bytes null por fila
int num_null_bytes(int width)
{
    int nullbytes = 0;
    width *= 3;

    while(width % 4 != 0)
    {
	nullbytes++;
	width++;
    }

    return nullbytes;
}

// Convirtiendo matrix a blanco y negro
void ctobw(Pixel **matrix, int height, int width)
{
    int x, y;
    uint8_t greyscale;
    Pixel *aux;

    #pragma omp parallel private(x, aux)
    {
	#pragma omp for
	for (y = 0; y < height; y++)
	    for (x = 0; x < width; x++)
	    {
		aux = (*matrix) + y * width + x;
		greyscale = (aux->red + aux->green + aux->blue) / 3;

		memcpy(&(aux->red), &greyscale, sizeof(uint8_t));
		memcpy(&(aux->green), &greyscale, sizeof(uint8_t));
		memcpy(&(aux->blue), &greyscale, sizeof(uint8_t));
	    }
    }
}

void rotate(Pixel **output, Pixel *matrix, int degrees, int height, int width)
{
    int cx = width/2, cy = height/2, x, y, xn, yn;
    double radians = (degrees * 3.14159) / 180;

    #pragma omp parallel private(x, xn, yn)
    {
	#pragma omp for
	for (y = 0; y < height; y++)
	    for (x = 0; x < width; x++)
	    {
		xn = cos(radians) * (x - cx) - sin(radians) * (y - cy) + cx;
		yn = sin(radians) * (x - cx) + cos(radians) * (y - cy) + cy;

		if (xn <= width && xn >= 0 && yn <= height && yn >= 0)
		    memcpy(*output + yn * width + xn, matrix + y * width + x, sizeof(uint8_t) * 3);
	    }
    }
}
