CC = gcc
CFLAGS = -Wall -g

SRC = $(wildcard *.c)
TARGET = programa

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean