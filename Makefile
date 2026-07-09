# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -g -Wall -Wextra -Wpedantic

# Executable name
TARGET = app

# Object files
OBJS = main.o book.o library.o utils.o

# Default target
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Object file rules
main.o: main.cpp library.hpp book.hpp utils.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

book.o: book.cpp book.hpp
	$(CXX) $(CXXFLAGS) -c book.cpp -o book.o

library.o: library.cpp library.hpp book.hpp
	$(CXX) $(CXXFLAGS) -c library.cpp -o library.o

utils.o: utils.cpp utils.hpp
	$(CXX) $(CXXFLAGS) -c utils.cpp -o utils.o

# Clean generated files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: clean