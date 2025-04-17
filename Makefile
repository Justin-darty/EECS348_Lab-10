# Makefile for Lab 10 - Calculator
# Author: Justin Daugherty
# Date: April 16, 2025
CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = calculator
OBJS = main.o calculator.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp calculator.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

calculator.o: calculator.cpp calculator.hpp
	$(CXX) $(CXXFLAGS) -c calculator.cpp

clean:
	rm -f *.o $(TARGET)
