CC=gcc
CFLAGS=-Wall

EXECUTABLE=list
EXECUTABLE3=list2
#EXECUTABLE2=llist

#all: $(EXECUTABLE) $(EXECUTABLE2) $(EXECUTABLE3)
all: $(EXECUTABLE) $(EXECUTABLE3)

list: list.o main.c
	$(CC) $(CFLAGS) list.o main.c -o $(EXECUTABLE)
list.o: list.h 

list2: list2.o main.c
	$(CC) $(CFLAGS) list2.o -o $(EXECUTABLE3)
list2.o: list2.c 

clean:
	rm -rf *.o *.gch $(EXECUTABLE) $(EXECUTABLE2) core*
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
