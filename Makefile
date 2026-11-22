CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = GuessTheNum.exe
SRC = GuessTheNum.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	del /Q $(TARGET) 2>nul

.PHONY: all clean
