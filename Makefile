CC=gcc
CFLAGS= -Wall -Werror

all: main.c
	$(CC) $(CFLAGS) -o main main.c

clean:
	rm -f *.o
