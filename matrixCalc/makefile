CC = gcc
CFLAGS = -Wall -ansi -pedantic
LIBS = -lm

all: mainmat

mainmat: mainmat.c mymat.c errors.c commands.c print.c 
	$(CC) $(CFLAGS) mainmat.c mymat.c errors.c commands.c print.c -o mainmat $(LIBS)