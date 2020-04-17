# James Busch
# 24/03/20
#
# This is the makefile to test

SRCDIR = ./src/
BINDIR = ./bin/
INCDIR = ./include/

CC = gcc
CFLAGS = -std=c99 -Wall -g -pedantic -I./include
OBJECTS = $(BINDIR)main.o $(BINDIR)Linked_List.o $(BINDIR)Linked_List_Tester.o

all: $(BINDIR)tester

$(BINDIR)tester: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(BINDIR)main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) -c $(SRCDIR)main.c -o $@

$(BINDIR)Linked_List.o: $(SRCDIR)Linked_List.c $(INCDIR)Linked_List.h
	$(CC) $(CFLAGS) -c $(SRCDIR)Linked_List.c -o $@

$(BINDIR)Linked_List_Tester.o: $(SRCDIR)Linked_List_Tester.c $(INCDIR)Linked_List_Tester.h
	$(CC) $(CFLAGS) -c $(SRCDIR)Linked_List_Tester.c -o $@

run:
	$(BINDIR)tester

memtest:
	valgrind --leak-check=full $(BINDIR)tester

clean:
	rm $(BINDIR)main.o $(BINDIR)Linked_List.o $(BINDIR)tester