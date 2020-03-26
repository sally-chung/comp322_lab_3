# Name: Sally Chung
# Project: Lab 3: Catcher

EXECUTABLES=catcher
SRC=catcher.c
OBJ=catcher.o

CC=gcc
CFLAGS=-g

all: $(EXECUTABLES)

	$(EXECUTABLES): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

catcher: catcher.c
	gcc -g -c catcher.c
	gcc -g -o $@ catcher.o

clean:
	rm -f $(EXECUTABLES) $(OBJ) 