.PHONY: default all clean

CXX = g++

CFLAGS = -std=c++14 -Werror -Wpedantic -Wuninitialized -O2 

default:
	$(CXX) $(CFLAGS) hw4.cpp -o hw4
	./hw4

clean:
	rm -f *.o *.out
