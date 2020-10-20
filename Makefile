CC = g++
CFLAGS = -Wall
INCLUDE = include//bigint.h include//cbigint.h

BIN = bin//
SRC = src//

all: $(BIN)cbigint.dll $(BIN)bigint.dll

$(BIN)cbigint.dll: cbind.o $(BIN)bigint.dll
	$(CC) -shared $(CFLAGS) -o $@ $< $(BIN)bigint.dll

$(BIN)bigint.dll: bigint.o
	$(CC) -shared $(CFLAGS) -o $@ $<

%.o: $(SRC)%.cc $(INCLUDE)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm *.o
