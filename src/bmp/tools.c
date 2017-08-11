#include <stdio.h>
#include <inttypes.h>
#include <string.h>

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
void ctobw(Pixel **matrix, int pixels)
{
    int i;
    uint8_t greyscale, *color;
    Pixel *aux;

    for(i = 0; i < pixels; i++)
    {
	aux = (*matrix) + i;

	greyscale = (aux->red + aux->green + aux->blue) / 3;

	color = &(aux->red);
	*color = greyscale;
	color = &(aux->green);
	*color = greyscale;
	color = &(aux->blue);
	*color = greyscale;
    }
}
