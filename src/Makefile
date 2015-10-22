#
# fileinfo := Makefile for decimus class
# author := Miguel Perez-Xochicale
# version := alpha00
#
# https://github.com/mxochicale/decimus
# 	

CXX=g++

##
# If you've installed Armadillo and boost's headers manually, 
# you should need to tell the compiler where they are.
LIB_DEP_PATH = ~/.lib_dependencies

ARMA_INCLUDE_FLAG = -I ${LIB_DEP_PATH}/armadillo-5.100.1/include
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

OUT = /out 


CXXFLAGS = $(ARMA_INCLUDE_FLAG) $(FLAGS) $(BOOST_INCLUDE_FLAG) $(BOOST_LIB_FLAG) $(OPT)


all: main

main: main.cpp
	g++ $(CXXFLAGS) -o $@ $< $(CLASSES) $(LIB_FLAGS)

.PHONY: clean help

clean: 
	rm -f main example *.*~ *~
	@echo "Clean done"

help:
	@echo "Please use \`make <target>' where <target> is one of"
	@echo " clean to remove binary and temporary files"                       
