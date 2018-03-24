CXXFLAGS=-std=c++14

main: main.o ascii.o
				g++ -o main main.o ascii.o

tests: tests.o ascii.o
				g++ -o tests tests.o ascii.o

tests.o: tests.cpp ascii.h

main.o: main.cpp ascii.h
				g++ $(CXXFLAGS) -c main.cpp

ascii.o: ascii.cpp ascii.h
				g++ $(CXXFLAGS) -c ascii.cpp
clean:
				rm -f main.o ascii.o
