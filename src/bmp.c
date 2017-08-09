#include "bmp.h"
uint8_t bmp_sign[2] = {0x42, 0x4d};

int bmp(FILE *file)
{
    BMPHeader *header;

    header = malloc(sizeof(BMPHeader));

    get_header(header, file);

    printf("%s", header->type);

}

void get_header(BMPHeader *header, FILE *file)
{
    header->type = malloc(sizeof(uint8_t) * 2);
    header->size= malloc(sizeof(uint8_t) * 4);
    header->reserved1 = malloc(sizeof(uint8_t) * 2);
    header->reserved2 = malloc(sizeof(uint8_t) * 2);
    header->offset = malloc(sizeof(uint8_t) * 4);

    fseek(file, 0, SEEK_SET);

    fread(header->type, sizeof(uint8_t), 2, file);
    fread(header->size, sizeof(uint8_t), 4, file);
    fread(header->reserved1, sizeof(uint8_t), 2, file);
    fread(header->reserved2, sizeof(uint8_t), 2, file);
    fread(header->offset, sizeof(uint8_t), 4, file);
}

int isBmpImage(FILE *file)
{
    uint8_t sign[2];

    fseek(file, 0, SEEK_SET);
    fread(sign, sizeof(uint8_t), 2, file);

    if (memcmp(bmp_sign, sign, 2) != 0)
	return 1;

    return 0;
}
