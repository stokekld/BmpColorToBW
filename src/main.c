#include <stdio.h>

int options(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int ret;

    ret = options(argc, argv);
    if (ret != 0)
	return 1;

    printf("Hola mundo %s\n", argv[1]);
}

int options(int argc, char *argv[])
{
    if (argc != 2)
	return 1;

    return 0;
}
