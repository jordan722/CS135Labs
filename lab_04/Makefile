CXXFLAGS=-std=c++14

main: main.o shapes.o
				g++ -o main main.o shapes.o

main.o: main.cpp shapes.h
				g++ $(CXXFLAGS) -c main.cpp

shapes.o: shapes.cpp shapes.h
				g++ $(CXXFLAGS) -c shapes.cpp
clean:
				rm -f main.o shapes.o
