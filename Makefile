CC=gcc
CFLAGS=-Wall

EXECUTABLE=list
EXECUTABLE2=llist
EXECUTABLE3=list2

all: $(EXECUTABLE) $(EXECUTABLE2) $(EXECUTABLE3)

list: list.o main.c
	$(CC) $(CFLAGS) list.o main.c -o $(EXECUTABLE)
list.o: list.h 

llist: linkedlist.o main.c
	$(CC) $(CFLAGS) linkedlist.o main1.c -o $(EXECUTABLE2)
linkedlist.o: linkedlist.h 

list2: list2.o main.c
	$(CC) $(CFLAGS) list2.o -o $(EXECUTABLE3)
list2.o: list2.c 

clean:
	rm -rf *.o *.gch $(EXECUTABLE) $(EXECUTABLE2)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
