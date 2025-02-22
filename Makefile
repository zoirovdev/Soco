CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = main.c pacman.c
OBJ = $(SRC:.c=.o)

all: pacman

pacman: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c pacman.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o pacman

