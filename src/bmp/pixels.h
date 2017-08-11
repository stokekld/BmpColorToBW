
// Estructura para pixel
typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Pixel;

//void get_matrix(Pixel *px, FILE *file, int pixels, int width, int nullbts);
void get_matrix(Pixel *px, FILE *file, int high, int width, int nullbts);
