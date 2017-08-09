#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct {
    uint8_t *type;
    uint8_t *size;
    uint8_t *reserved1;
    uint8_t *reserved2;
    uint8_t *offset;
} BMPHeader;

int bmp(FILE *file);
void get_header(BMPHeader *header, FILE *file);
int isBmpImage(FILE *file);
