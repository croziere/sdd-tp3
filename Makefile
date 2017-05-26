CC=gcc
CFLAGS=-I.
DEPS=arbre.h dico.h helpers.h pile.h
OBJ=arbre.o dico.o pile.o main.o

%.o: %.c