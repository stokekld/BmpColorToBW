#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include "pixels.h"

#include "output.h"

uint8_t nullchar = 0x00;

void dumb_file(BMPHeader * header, IHeader *iheader, Pixel *matrix, int pixels, int width, int nullbts)
{
    int i, row = 1;
    FILE *output;
    Pixel *aux;

    output = fopen("salida.bmp", "wb");

    fwrite(header->type, sizeof(uint8_t), 2, output);
    fwrite(&(header->size), sizeof(uint32_t), 1, output);
    fwrite(header->reserved1, sizeof(uint8_t), 2, output);
    fwrite(header->reserved2, sizeof(uint8_t), 2, output);
    fwrite(&(header->offset), sizeof(uint32_t), 1, output);

    fwrite(&(iheader->size), sizeof(uint32_t), 1, output);
    fwrite(&(iheader->width), sizeof(uint32_t), 1, output);
    fwrite(&(iheader->height), sizeof(uint32_t), 1, output);
    fwrite(&(iheader->planes), sizeof(uint16_t), 1, output);
    fwrite(&(iheader->count), sizeof(uint16_t), 1, output);
    fwrite(&(iheader->compres), sizeof(uint32_t), 1, output);
    fwrite(&(iheader->sizeImg), sizeof(uint32_t), 1, output);
    fwrite(&(iheader->pxxm), sizeof(uint32_t), 1, output);
    fwrite(&(iheader->pxym), sizeof(uint32_t), 1, output);
    fwrite(&(iheader->colorMap), sizeof(uint32_t), 1, output);
    fwrite(&(iheader->colorImp), sizeof(uint32_t), 1, output);

    for(i = 0; i < pixels; i++)
    {
	aux = matrix + i;
	fwrite(&(aux->red), sizeof(uint8_t), 1, output);
	fwrite(&(aux->green), sizeof(uint8_t), 1, output);
	fwrite(&(aux->blue), sizeof(uint8_t), 1, output);

	if(row == width)
	{
	    fwrite(&nullchar, sizeof(uint8_t), nullbts, output);
	    row = 0;
	}

	row++;
    }

    fclose(output);
}
