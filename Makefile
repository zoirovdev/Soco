
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = main.c
OBJ = $(SRC:.c=.o)
EXE = exe


all: $(EXE)


$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(EXE) $(OBJ)
