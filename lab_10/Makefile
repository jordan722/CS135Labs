CXXFLAGS=-std=c++14

main: main.o functions.o
				g++ -o main main.o functions.o

tests: tests.o functions.o
				g++ -o tests tests.o functions.o

tests.o: tests.cpp functions.h

main.o: main.cpp functions.h
				g++ $(CXXFLAGS) -c main.cpp

functions.o: functions.cpp functions.h
				g++ $(CXXFLAGS) -c functions.cpp
clean:
				rm -f main.o functions.o
