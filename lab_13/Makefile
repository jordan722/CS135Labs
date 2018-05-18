CXXFLAGS=-std=c++14

main: taska taskb taskc taskd

debug: CXXFLAGS:=$(CXXFLAGS) -g

taska: social.cpp
				g++ $(CXXFLAGS) -o taska social.cpp

taskb: social2.cpp
				g++ $(CXXFLAGS) -o taskb social2.cpp

taskc: social3.cpp
				g++ $(CXXFLAGS) -o taskc social3.cpp

taskd: social4.cpp
				g++ $(CXXFLAGS) -o taskd social4.cpp

clean:
				rm -f main.o functions.o *.o *.out main tests taska taskb taskc taskd
