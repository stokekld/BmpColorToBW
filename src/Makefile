CC=gcc

MAIN=main.c
MAIN_O=main

OPTS=options.c
OPTS_H=options.h

BMP=bmp.c
BMP_H=bmp.h

all: $(MAIN_O)

$(MAIN_O): $(MAIN) $(OPTS) $(OPTS_H) $(BMP) $(BMP_H)
	$(CC) $(MAIN) $(OPTS) $(BMP) -o $(MAIN_O)

clean:
	rm $(MAIN_O)
