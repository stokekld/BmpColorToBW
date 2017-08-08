#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct {

    uint8_t *length;
    uint8_t *type;
    uint8_t *data;
    uint8_t *crc;

} Layout;

int isPngFile(FILE *file);
void get_chunks(FILE *file);
int get_length(uint8_t *buffer);
int get_layout(Layout *l, FILE *file, int offset);
void free_layout(Layout *l);
