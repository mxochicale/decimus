# Makefile for the RazorAHRS C++ project Using armadillo library
# Miguel Xochicale

CC=g++
LIB_FLAGS=-lpthread 
CFLAGS=-Wall -D_REENTRANT


EXECUTABLE = kproject
BUILD_DIR = build

DEPS=RazorAHRS.h
SOURCES=main.cpp RazorAHRS.cpp
OBJECTS= $(SOURCES:.cpp=.o)


LIB_DEP_PATH=~/.lib_dependencies
EIGEN_VER=armadillo-5.100.1
EIGEN_INCLUDE_FLAG= -I ${LIB_DEP_PATH}/${EIGEN_VER}/include
EIGENFLAGS=${ARMA_INCLUDE_FLAG} ${OPT}



%.o: %.cpp $(DEPS)
	$(CC) -c $<  $(CFLAGS) $(LIB_FLAGS)

all: $(OBJECTS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(OBJECTS) $(CFLAGS) $(LIB_FLAGS) -o $(BUILD_DIR)/$(EXECUTABLE)

clean:
	rm -f *.o *~ $(EXECUTABLE)
	rm -rf $(BUILD_DIR)
	rm -rf .kdev4
	@echo "Clean done"
