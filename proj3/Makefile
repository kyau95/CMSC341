.PHONY: all test clean

CFLAGS = -std=c++14 -g -Werror -Wpedantic -O2

all:
	g++ $(CFLAGS) driver.cpp pqueue.cpp -o proj3
	./proj3

test:
	g++ $(CFLAGS) mytest.cpp pqueue.cpp -o test
	./test

clean:
	rm -f *.o proj3
