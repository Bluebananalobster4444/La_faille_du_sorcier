CC = gcc
CFLAGS = -Wall -Wextra -I.
TARGET = jeu.out

rwildcard = $(foreach d,$(wildcard $(1)*),$(call rwildcard,$(d)/,$(2)) $(filter $(subst *,%,$(2)),$(d)))
SRC = $(call rwildcard,,*.c)

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
