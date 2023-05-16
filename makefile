
all : test

test : main.o sorts.o
	g++ main.o sorts.o -o test

main.o : main.cpp
	g++ -c main.cpp

sorts.o : sorts.cpp
	g++ -c sorts.cpp

clean :
	rm -rf *.o test
