CC=gcc

MAIN=main.c
MAIN_O=main

OPTS=options.c

all: $(MAIN_O)

$(MAIN_O): $(MAIN) $(OPTS)
	$(CC) $(MAIN) $(OPTS) -o $(MAIN_O)

clean:
	rm $(MAIN_O)
