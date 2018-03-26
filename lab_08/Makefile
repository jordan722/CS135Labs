CXXFLAGS=-std=c++14

main: main.o indent.o
				g++ -o main main.o indent.o

tests: tests.o indent.o
				g++ -o tests tests.o indent.o

tests.o: tests.cpp indent.h

main.o: main.cpp indent.h
				g++ $(CXXFLAGS) -c main.cpp

indent.o: indent.cpp indent.h
				g++ $(CXXFLAGS) -c indent.cpp
clean:
				rm -f main.o indent.o
