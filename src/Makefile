CC=gcc

MAIN_C=main.c
MAIN_O=bmpctbw

OPTS_C=options.c
OPTS_H=options.h

BMP_DIR=./bmp

BMP_C=$(BMP_DIR)/bmp.c
BMP_H=$(BMP_DIR)/bmp.h
BMP_O=bmp.o

HDS_C=$(BMP_DIR)/headers.c
HDS_H=$(BMP_DIR)/headers.h
HDS_O=headers.o

TLS_C=$(BMP_DIR)/tools.c
TLS_H=$(BMP_DIR)/tools.h
TLS_O=tools.o

PXS_C=$(BMP_DIR)/pixels.c
PXS_H=$(BMP_DIR)/pixels.h
PXS_O=pixels.o

OPT_C=$(BMP_DIR)/output.c
OPT_H=$(BMP_DIR)/output.h
OPT_O=output.o

all: $(MAIN_O)

$(BMP_O): $(BMP_C) $(BMP_H)
	$(CC) -c $(BMP_C) -o $(BMP_O)

$(HDS_O): $(HDS_C) $(HDS_H)
	$(CC) -c $(HDS_C) -o $(HDS_O)

$(TLS_O): $(TLS_C) $(TLS_H)
	$(CC) -fopenmp -c $(TLS_C) -o $(TLS_O) -lm

$(PXS_O): $(PXS_C) $(PXS_H)
	$(CC) -c $(PXS_C) -o $(PXS_O)

$(OPT_O): $(OPT_C) $(OPT_H)
	$(CC) -c $(OPT_C) -o $(OPT_O)

$(MAIN_O): $(MAIN_C) $(OPTS_C) $(OPTS_H) $(BMP_O) $(HDS_O) $(TLS_O) $(PXS_O) $(OPT_O)
	$(CC) -fopenmp -I $(BMP_DIR) -o $(MAIN_O) $(BMP_O) $(HDS_O) $(TLS_O) $(PXS_O) $(OPT_O) $(MAIN_C) $(OPTS_C) -lm

clean:
	rm $(MAIN_O) $(BMP_O) $(HDS_O) $(TLS_O) $(PXS_O) $(OPT_O)
