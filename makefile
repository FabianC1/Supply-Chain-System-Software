CXX = g++
CXXFLAGS = -g -Wall

program: main.cpp
	$(CXX) $(CXXFLAGS) -o program main.cpp

clean:
	rm -f program
