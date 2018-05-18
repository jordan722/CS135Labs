CXXFLAGS=-std=c++14

main: main.o funcs.o 
				g++ -o main main.o funcs.o


debug: CXXFLAGS:=$(CXXFLAGS) -g
debug:main

tests: tests.o funcs.o
				g++ -o tests tests.o funcs.o

tests.o: tests.cpp def.h

main.o: main.cpp def.h
				g++ $(CXXFLAGS) -c main.cpp

funcs.o: funcs.cpp def.h
				g++ $(CXXFLAGS) -c funcs.cpp


clean:
				rm -f main.o funcs.o *.o *.out
