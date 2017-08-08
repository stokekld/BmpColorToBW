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
    int i;
    int length;
    uint8_t buffer[4], type[4], CRC[4];

    fseek(file, 8, SEEK_SET);

    do
    {
	fread(buffer, sizeof(uint8_t), 4, file);

	length = get_length(buffer);

	fread(type, sizeof(uint8_t), 4, file);
	printf("%d %s\n", length, type);

	fseek(file, length, SEEK_CUR);

	fread(CRC, sizeof(uint8_t), 4, file);
	/*printf("%x", CRC[3]);*/
    }while(memcmp(IEND, type, 4) != 0);

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
