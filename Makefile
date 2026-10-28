TARGET = jeu

CC     = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2

SRC = $(wildcard *.c assets/vie/*.c assets/carte/*.c Mvt/joueur/*.c)
OBJ = $(SRC:.c=.o)

ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
    LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm
    RM      = del /Q
else
    LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
    RM      = rm -f
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
