#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

// Estructura header del archivo BMP
typedef struct {
    uint8_t type[2];
    uint32_t size;
    uint8_t reserved1[2];
    uint8_t reserved2[2];
    uint32_t offset;
} BMPHeader;

// Estructura header de la imagen
typedef struct {
    uint32_t size;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t count;
} IHeader;

// Estructura para pixel
typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Pixel;

int bmp(FILE *file);
void get_header(BMPHeader *header, FILE *file);
int isBmpImage(FILE *file);
void get_iHeader(IHeader *header, FILE *file);
void get_pixel(Pixel *px, FILE *file);
