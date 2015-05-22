# 
# CopyLeft (C) 2015  Miguel Perez-Xochicale
# [https://github.com/mxochicale/]
# 
#	This Makefile is part of Decimus Application
#	   
#	# If you've installed Armadillo and boost's headers manually,
#       # you may need to tell the compiler where they are.
#	

fileinfo := Makefile for decimus app
author   := Miguel Perez-Xochicale
version  := 0.1.0

# CHANGES:
# mxochicale (2015-05-18):
# * Add clean temporary files
# * Add help target 

# ** Bump version to 0.1.0

CXX=g++


##
#If you've installed Armadillo and boost's headers manually, 
#you may need to tell the compiler where they are.
##
ARMA_INCLUDE_FLAG = -I ../armadillo-5.100.1/include

BOOST_INCLUDE_FLAG = -I ../boost-1.58.0/include
BOOST_LIB_FLAG=  -L ../boost-1.58.0/lib64


LIB_FLAGS = -lblas -llapack -lpthread

OPT = -O2
## As the Armadillo library uses recursive templates, compilation times depend on the level of optimisation:
## -O0: quick compilation, but the resulting program will be slow
## -O1: good trade-off between compilation time and execution speed
## -O2: produces programs which have almost all possible speedups, but compilation takes longer
## -O3: enables auto vectorisation when using gcc


CLASSES = RazorAHRS.cpp Decimus.cpp 
FLAGS = -Wall -D_REENTRANT 

CXXFLAGS = $(ARMA_INCLUDE_FLAG) $(FLAGS) $(BOOST_INCLUDE_FLAG) $(BOOST_LIB_FLAG) $(OPT)

all: main

main: main.cpp
	g++ $(CXXFLAGS) -o $@ $< $(CLASSES) $(LIB_FLAGS)
	
.PHONY: clean help

clean: 
	rm -f main *.*~ *~
	@echo "Clean done"
                  
help:
	@echo "Please use \`make <target>' where <target> is one of"
	@echo " clean to remove binary and temporary files"                       
