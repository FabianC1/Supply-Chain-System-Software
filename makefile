CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

program: main.cpp
	$(CXX) $(CXXFLAGS) -o program main.cpp

clean:
	rm -f program
