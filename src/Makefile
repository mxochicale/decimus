# fileinfo := Makefile for decimus class
# author := Miguel Xochicale

# TODO
# * add line to create build directory [Wed Dec 16 15:50:04 GMT 2015]
# this might help: http://stackoverflow.com/questions/1950926/create-directories-using-make-file


CXX=g++

##
# If you've installed Armadillo and boost's headers manually,
# you should need to tell the compiler where they are.
LIB_DEP_PATH = ~/.lib_dependencies

#ARMA_VER = armadillo-5.100.1
ARMA_VER = armadillo-6.700.3

ARMA_INCLUDE_FLAG = -I ${LIB_DEP_PATH}/${ARMA_VER}/include
BOOST_INCLUDE_FLAG = -I ${LIB_DEP_PATH}/boost-1.58.0/include
BOOST_LIB_FLAG=  -L ${LIB_DEP_PATH}/boost-1.58.0/lib64

LIB_FLAGS = -lblas -llapack -lpthread -lboost_system
#-lboost_system (need it to create a directory)

CLASSES = RazorAHRS.cpp Decimus.cpp
FLAGS = -Wall -D_REENTRANT

OPT = -O2
## As the Armadillo library uses recursive templates, compilation times depend on the level of optimisation:
## -O0: quick compilation, but the resulting program will be slow
## -O1: good trade-off between compilation time and execution speed
## -O2: produces programs which have almost all possible speedups, but compilation takes longer
## -O3: enables auto vectorisation when using gcc


EXECUTABLE = kproject
BUILD_DIR = build




CXXFLAGS = $(ARMA_INCLUDE_FLAG) $(FLAGS) $(BOOST_INCLUDE_FLAG) $(BOOST_LIB_FLAG) $(OPT)

all: main

main: main.cpp
	mkdir -p $(BUILD_DIR)
	g++ $(CXXFLAGS) $< $(CLASSES) $(LIB_FLAGS) -o $(BUILD_DIR)/$(EXECUTABLE)



.PHONY: clean help

clean:
	rm -f main example *.*~ *~  $(EXECUTABLE)
	rm -rf .kdev4
	rm -rf build
	@echo "Clean done"

help:
	@echo "Please use \`make <target>' where <target> is one of"
	@echo " clean to remove binary and temporary files"
