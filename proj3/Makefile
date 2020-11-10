.PHONY: all test clean

CFLAGS = -std=c++14 -g -Werror -Wpedantic -O2

all:
	g++ $(CFLAGS) driver.cpp pqueue.cpp -o proj3

test:
	g++ $(CFLAGS) mytest.cpp pqueue.cpp -o test
	
clean:
	rm -f *.o proj3

valproj:
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes --vgdb=no ./proj3

valtest:
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes --vgdb=no ./test