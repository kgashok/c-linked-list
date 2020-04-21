CC=gcc
CFLAGS=-Wall

EXECUTABLE=list
EXECUTABLE2=llist

all: $(EXECUTABLE) $(EXECUTABLE2)

list: list.o main.c
	$(CC) $(CFLAGS) list.o main.c -o $(EXECUTABLE)
list.o: list.h 

llist: linkedlist.o main.c
	$(CC) $(CFLAGS) linkedlist.o main1.c -o $(EXECUTABLE2)
linkedlist.o: linkedlist.h 

clean:
	rm -rf *.o *.gch $(EXECUTABLE) $(EXECUTABLE2)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
