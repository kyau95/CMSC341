CXX = g++

CFLAG = -std=c++14 -Werror -Wpedantic -Wuninitialized -fpermissive -O2 

.PHONY: default test clean

default:
	$(CXX) $(CFLAG) driver.cpp -o proj4
	./proj4

test:
	$(CXX) $(CFLAG) mytest.cpp -o test
	./test

valtest:
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes --vgdb=no ./test

valproj:
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes --vgdb=no ./proj4

clean:
	rm -f *.o proj4 test