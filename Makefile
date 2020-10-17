CC = g++
CFLAGS = -Wall
INCLUDE = bigint.h

bin//bigint.dll: bigint.o
	$(CC) -shared $(CFLAGS) -o $@ $<

%.o: %.cc $(INCLUDE)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm *.o
