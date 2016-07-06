

CC=g++
LIB_FLAGS=-lpthread
CFLAGS=-Wall -D_REENTRANT


EXECUTABLE = kproject
BUILD_DIR = build

DEPS=RazorAHRS.h
SOURCES=main.cpp RazorAHRS.cpp
OBJECTS= $(SOURCES:.cpp=.o)


LIB_DEP_PATH=~/.lib_dependencies
lib_name=eigen
lib_version=3.2.8
EIGEN_INCLUDE_FLAG = -I ${LIB_DEP_PATH}/${lib_name}-${lib_version}/include/eigen3/


%.o: %.cpp $(DEPS)
	$(CC) -c $<  $(CFLAGS) $(LIB_FLAGS) $(EIGEN_INCLUDE_FLAG)

all: $(OBJECTS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(OBJECTS) $(CFLAGS) $(LIB_FLAGS) $(EIGEN_INCLUDE_FLAG) -o $(BUILD_DIR)/$(EXECUTABLE)


clean:
	rm -f *.o *~ $(EXECUTABLE)
	rm -rf $(BUILD_DIR)
	rm -rf .kdev4
	@echo "Clean done"
