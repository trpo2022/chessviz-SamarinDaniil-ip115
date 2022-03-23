CFLAGS=-Wall -Wextra -Werror
CPPFLAGS=-MMD
CC=gcc
LIB_NAME=board_read

all: main.o lib$(LIB_NAME).a 
		$(CC) $(CFLAGS) -o $@ $^

main.o: src/chessviz/main.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

lib$(LIB_NAME).a: $(LIB_NAME).o
		ar -rcs $@ $^

$(LIB_NAME).o: src/chessviz/$(LIB_NAME).c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean: 
		rm -rf *.o