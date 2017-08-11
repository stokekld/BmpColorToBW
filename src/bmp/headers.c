#include <stdio.h>
#include <inttypes.h>

#include "headers.h"

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
