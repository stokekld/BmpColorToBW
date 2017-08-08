CC=gcc

MAIN=main.c
MAIN_O=main

OPTS=options.c
OPTS_H=options.h

PNG=png.c
PNG_H=png.h

all: $(MAIN_O)

$(MAIN_O): $(MAIN) $(OPTS) $(OPTS_H) $(PNG) $(PNG_H)
	$(CC) $(MAIN) $(OPTS) $(PNG) -o $(MAIN_O)

clean:
	rm $(MAIN_O)
