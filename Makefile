CC = g++
CFLAGS = -Wall
INCLUDE = bigint.h cbigint.h

BIN = bin//

all: $(BIN)cbigint.dll $(BIN)bigint.dll

$(BIN)cbigint.dll: cbind.o $(BIN)bigint.dll
	$(CC) -shared $(CFLAGS) -o $@ $< $(BIN)bigint.dll

$(BIN)bigint.dll: bigint.o
	$(CC) -shared $(CFLAGS) -o $@ $<

%.o: %.cc $(INCLUDE)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm *.o
