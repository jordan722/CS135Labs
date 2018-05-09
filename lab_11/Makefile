CXXFLAGS=-std=c++14

main: main.o funcs.o
				g++ -o main main.o funcs.o

tests: tests.o functions.o
				g++ -o tests tests.o funcs.o

tests.o: tests.cpp def.h

main.o: main.cpp def.h
				g++ $(CXXFLAGS) -c main.cpp

functions.o: funcs.cpp def.h
				g++ $(CXXFLAGS) -c funcs.cpp
clean:
				rm -f main.o functions.o
