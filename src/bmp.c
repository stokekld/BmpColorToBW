#include "bmp.h"

// Firma de archivo bmp
uint8_t bmp_sign[2] = {0x42, 0x4d};

// funcion principal
int bmp(FILE *file)
{
    BMPHeader header;
    IHeader iheader;
    Pixel px;

    get_header(&header, file);
    get_iHeader(&iheader, file);
    get_pixel(&px, file);

    printf("%d,", px.red);
    printf("%d,", px.green);
    printf("%d", px.blue);

}

// Funcion para obtener pixel
void get_pixel(Pixel *px, FILE *file)
{
    fseek(file, 54, SEEK_SET);

    fread(&(px->red), sizeof(uint8_t), 1, file);
    fread(&(px->green), sizeof(uint8_t), 1, file);
    fread(&(px->blue), sizeof(uint8_t), 1, file);
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
