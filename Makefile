CC = g++
CFLAGS = -Wall
INCLUDE = include//bigint.h include//cbigint.h

BIN = bin//
SRC = src//

EXT = dll

all: $(BIN)cbigint.$(EXT) $(BIN)bigint.$(EXT)

$(BIN)cbigint.$(EXT): cbind.o $(BIN)bigint.$(EXT)
	$(CC) -shared $(CFLAGS) -o $@ $< $(BIN)bigint.$(EXT)

$(BIN)bigint.$(EXT): bigint.o
	$(CC) -shared $(CFLAGS) -o $@ $<

%.o: $(SRC)%.cc $(INCLUDE)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm *.o
