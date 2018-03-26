CXXFLAGS=-std=c++14

main: main.o indent.o
				g++ -o main main.o indent.o

main.o: main.cpp indent.h
				g++ $(CXXFLAGS) -c main.cpp

indent.o: indent.cpp indent.h
				g++ $(CXXFLAGS) -c indent.cpp
clean:
				rm -f main.o indent.o
