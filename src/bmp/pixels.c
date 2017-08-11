#include <stdio.h>
#include <inttypes.h>

#include "pixels.h"

// Funcion para obtener pixel
void get_matrix(Pixel *px, FILE *file, int high, int width, int nullbts)
{
    int i, j;
    Pixel *aux;

    for (i = 0; i < high; i++)
    {
	fseek(file, 54 + (i * width * 3) + (nullbts * i), SEEK_SET);

	for (j = 0; j < width; j++)
	{
	    aux = px + (i * width) + j;

	    fread(&(aux->red), sizeof(uint8_t), 1, file);
	    fread(&(aux->green), sizeof(uint8_t), 1, file);
	    fread(&(aux->blue), sizeof(uint8_t), 1, file);
	}
    }
}
