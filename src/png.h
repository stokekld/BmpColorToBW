#include <stdio.h>
#include <inttypes.h>

int isPngFile(FILE *file);
void get_chunks(FILE *file);
int get_length(uint8_t *buffer);
