CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic
SYSTEM_TESTS = system_tests.cpp
CATCH_INCLUDE = catch.hpp

# Compilation rule for the executable
supply_chain_system: customer_info.o file_read.o main.o order_item.o product_item.o
	$(CXX) $(CXXFLAGS) -o supply_chain_system customer_info.o file_read.o main.o order_item.o product_item.o

# Test executable
system_tests: $(SYSTEM_TESTS) customer_info.o file_read.o order_item.o product_item.o
	$(CXX) $(CXXFLAGS) -o system_tests $(SYSTEM_TESTS) customer_info.o file_read.o order_item.o product_item.o $(CATCH_INCLUDE)

# Compilation rules for each source file
customer_info.o: customer_info.cpp customer_info.h
	$(CXX) $(CXXFLAGS) -c customer_info.cpp

file_read.o: file_read.cpp file_read.h
	$(CXX) $(CXXFLAGS) -c file_read.cpp

main.o: main.cpp customer_info.h order_item.h product_item.h
	$(CXX) $(CXXFLAGS) -c main.cpp

order_item.o: order_item.cpp order_item.h
	$(CXX) $(CXXFLAGS) -c order_item.cpp

product_item.o: product_item.cpp product_item.h
	$(CXX) $(CXXFLAGS) -c product_item.cpp

# Rule to clean object files and executable
clean:
	rm *.o
	rm supply_chain_system
	rm system_tests
