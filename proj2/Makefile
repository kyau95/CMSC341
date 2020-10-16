CC = g++

CFLAGS = -g -std=c++14 -Werror -O2

.PHONY: all clean

all: proj2

proj2: bNode.o bookTree.o wordTree.o
	$(CC) $(CFLAGS) bNode.o bookTree.o wordTree.o main.cpp -o proj2

maketest: bNode.o bookTree.o wordTree.o
	$(CC) $(CFLAGS) bNode.o bookTree.o wordTree.o mytest.cpp -o proj2

bNode.o: bNode.cpp bNode.h
	$(CC) $(CFLAGS) -c bNode.cpp

bookTree.o: bookTree.cpp bookTree.h
	$(CC) $(CFLAGS) -c bookTree.cpp

wordTree.o: wordTree.cpp wordTree.h
	$(CC) $(CFLAGS) -c wordTree.cpp

clean:
	-rm -f *.o *.out