#include <stdio.h>
#include <inttypes.h>

#include "pixels.h"

// Funcion para obtener pixel
void get_matrix(Pixel *px, FILE *file, int pixels, int width, int nullbts)
{
    int i, row = 1;
    Pixel *aux;
    
    fseek(file, 54, SEEK_SET);
    
    for (i = 0; i < pixels; i++)
    {
	aux = px + i;
	fread(&(aux->red), sizeof(uint8_t), 1, file);
	fread(&(aux->green), sizeof(uint8_t), 1, file);
	fread(&(aux->blue), sizeof(uint8_t), 1, file);

	if (row == width)
	{
	    fseek(file, nullbts, SEEK_CUR);
	    row = 0;
	}

	row++;
    }
}
