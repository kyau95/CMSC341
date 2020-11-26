.PHONY: default all clean

CXX = g++

CFLAGS = -g -std=c++14 -Werror -Wpedantic -Wuninitialized 

default:
	$(CXX) $(CFLAGS) hw4.cpp -o hw4
	./hw4

valhw:
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=med --track-origins=yes --vgdb=no ./hw4

clean:
	rm -f *.o *.out
