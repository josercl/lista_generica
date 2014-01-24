CC=gcc
CFLAGS=
CPPFLAGS=
INCFLAGS=-I../include
OBJECTS=main.o lista.o

all: main

main: $(OBJECTS)
	$(CC) -o $@ $(CPPFLAGS) $(CFLAGS) $(OBJECTS)

.SUFFIXES:
.SUFFIXES:	.c .cc .C .cpp .o

.c.o :
	$(CC) -o $@ -c $(CFLAGS) $< $(INCFLAGS)

clean:
	rm -rf *.o src/main src/*.o