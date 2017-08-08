#include "png.h"

uint8_t png_sign[8] = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a};
uint8_t IEND[4] = {0x49, 0x45, 0x4e, 0x44};


int isPngFile(FILE *file)
{
    uint8_t sign[8];

    fseek(file, 0, SEEK_SET);

    fread(&sign, sizeof(uint8_t), 8, file);

    if (memcmp(png_sign, sign, 8) != 0)
	return 1;

    return 0;
}

void get_chunks(FILE *file)
{
    Layout *l;
    int offset = 8, iend;


    do
    {
	l = (Layout *) malloc(sizeof(Layout));
	offset += get_layout(l, file, offset);
	printf("%c%c%c%c\n", l->type[0],l->type[1],l->type[2],l->type[3]);
	iend = memcmp(IEND, l->type, 4);
	free_layout(l);

    }while(iend != 0);

}

void free_layout(Layout *l)
{
    free(l->length);
    free(l->type);
    free(l->data);
    free(l->crc);

    free(l);
    
}

int get_layout(Layout *l, FILE *file, int offset)
{
    int data_len, layout_len;
    uint8_t buffer[4];

    fseek(file, offset, SEEK_SET);

    fread(buffer, sizeof(uint8_t), 4, file);
    data_len = get_length(buffer);
    layout_len = 4 + 4 + data_len + 4;

    fseek(file, offset, SEEK_SET);

    l->length = malloc(sizeof(uint8_t)*4);
    l->type = malloc(sizeof(uint8_t)*4);
    l->data = malloc(sizeof(uint8_t)*data_len);
    l->crc = malloc(sizeof(uint8_t)*4);

    fread(l->length, sizeof(uint8_t), 4, file);
    fread(l->type, sizeof(uint8_t), 4, file);
    fread(l->data, data_len, 1, file);
    fread(l->crc, sizeof(uint8_t), 4, file); 

    return layout_len;
}

int get_length(uint8_t *buffer)
{
    int i, length = 0;

    for (i = 0; i < 4; i++)
    {
	length += (buffer[i] << (24-8*i));
    }
    
    return length;
}
