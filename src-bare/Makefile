
#
# Makefile for the RazorAHRS C++ project
# Miguel Xochicale 

#$ g++ Example.cpp RazorAHRS.cpp -Wall -D_REENTRANT -lpthread -o example


CC=g++
LIB_FLAGS=-lpthread
CFLAGS=-Wall -D_REENTRANT

EXECUTABLE = example
DEPS=RazorAHRS.h
SOURCES=Example.cpp RazorAHRS.cpp
OBJECTS= $(SOURCES:.cpp=.o)



%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS) $(LIB_FLAGS)

all: $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(CFLAGS) $(LIB_FLAGS)

clean:
	rm -f *.o *~ $(EXECUTABLE)
