#include "bmp.h"

// Firma de archivo bmp
uint8_t bmp_sign[2] = {0x42, 0x4d};

// funcion principal
int bmp(FILE *file)
{
    int i;
    BMPHeader header;
    IHeader iheader;
    Pixel *matrix;

    get_header(&header, file);
    get_iHeader(&iheader, file);

    matrix = malloc(sizeof(Pixel) * iheader.width * iheader.height);

    get_matrix(matrix, file, iheader.width * iheader.height);

    dumb_file(&header, &iheader, matrix, iheader.width * iheader.height);

    /*for (i = 0; i < (iheader.width * iheader.height); i++)*/
    /*{*/
	/*printf("%x,", (matrix + i)->red);*/
	/*printf("%x,", (matrix + i)->green);*/
	/*printf("%x\n", (matrix + i)->blue);*/
    /*}*/

}

void dumb_file(BMPHeader * header, IHeader *iheader, Pixel *matrix, int pixels)
{
    int i;
    uint8_t greyscale;
    FILE *output;
    Pixel *aux;

    output = fopen("holamundo.bmp", "wb");

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
	greyscale = (aux->red + aux->green + aux->blue) / 3;
	fwrite(&(greyscale), sizeof(uint8_t), 1, output);
	fwrite(&(greyscale), sizeof(uint8_t), 1, output);
	fwrite(&(greyscale), sizeof(uint8_t), 1, output);
    }

    fclose(output);
}

// Funcion para obtener pixel
void get_matrix(Pixel *px, FILE *file, int pixels)
{
    int i;
    Pixel *aux;

    fseek(file, 54, SEEK_SET);
    
    for (i = 0; i < pixels; i++)
    {
	aux = px + i;
	fread(&(aux->red), sizeof(uint8_t), 1, file);
	fread(&(aux->green), sizeof(uint8_t), 1, file);
	fread(&(aux->blue), sizeof(uint8_t), 1, file);
    }
}

// Funcion para obtener header del archivo
void get_header(BMPHeader *header, FILE *file)
{
    fseek(file, 0, SEEK_SET);

    fread(header->type, sizeof(uint8_t), 2, file);
    fread(&(header->size), sizeof(uint32_t), 1, file);
    fread(header->reserved1, sizeof(uint8_t), 2, file);
    fread(header->reserved2, sizeof(uint8_t), 2, file);
    fread(&(header->offset), sizeof(uint32_t), 1, file);
}

// Funcion para obtener header de la imagen
void get_iHeader(IHeader *header, FILE *file)
{
    fseek(file, 14, SEEK_SET);

    fread(&(header->size), sizeof(uint32_t), 1, file);
    fread(&(header->width), sizeof(uint32_t), 1, file);
    fread(&(header->height), sizeof(uint32_t), 1, file);
    fread(&(header->planes), sizeof(uint16_t), 1, file);
    fread(&(header->count), sizeof(uint16_t), 1, file);
    fread(&(header->compres), sizeof(uint32_t), 1, file);
    fread(&(header->sizeImg), sizeof(uint32_t), 1, file);
    fread(&(header->pxxm), sizeof(uint32_t), 1, file);
    fread(&(header->pxym), sizeof(uint32_t), 1, file);
    fread(&(header->colorMap), sizeof(uint32_t), 1, file);
    fread(&(header->colorImp), sizeof(uint32_t), 1, file);
}

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
