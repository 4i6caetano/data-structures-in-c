CC = gcc
CFLAGS = -Wall -g

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = programa

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean