#include <stdio.h>

int options(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int ret;
    int c;

    ret = options(argc, argv);
    if (ret != 0)
	return 1;

    FILE *img = fopen(argv[1], "rb");

    if (img == NULL)
    {
	perror("No se pudo abrir el archivo.");
	return 1;
    }

    do{
	c = fgetc(img);

	if (c != EOF)
	    printf("%x\n", c);

    }while(c != EOF);


    fclose(img);

}

int options(int argc, char *argv[])
{
    if (argc != 2)
	return 1;

    return 0;
}
