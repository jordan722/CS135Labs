CXXFLAGS=-std=c++14

main: main.o numbers.o
				g++ -o main main.o numbers.o

tests: tests.o numbers.o
				g++ -o tests tests.o numbers.o

tests.o: tests.cpp numbers.h

main.o: main.cpp numbers.h
				g++ $(CXXFLAGS) -c main.cpp

numbers.o: numbers.cpp numbers.h
				g++ $(CXXFLAGS) -c numbers.cpp
clean:
				rm -f main.o numbers.o
