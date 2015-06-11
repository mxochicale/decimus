fileinfo := Makefile for testing libraries
author := Miguel P. Xochicale
version := 001 
#TODO := concatenate the current directory with the armadillo path 
#     ./boostregex: error while loading shared libraries: libboost_regex.so.1.58.0: cannot open shared object file: No such file or directory
#current_dir = $(shell pwd)
#current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))i
#CUR_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

CXX=g++

##
# If you've installed Armadillo and boost's headers manually, 
# you should need to tell the compiler where they are.
LIB_DEP_PATH = /home/map479/lib_dependencies

ARMA_INCLUDE_FLAG = -I ${LIB_DEP_PATH}/armadillo-5.100.1/include
BOOST_INCLUDE_FLAG = -I ${LIB_DEP_PATH}/boost-1.58.0/include
BOOST_LIB_FLAG=  -L ${LIB_DEP_PATH}/boost-1.58.0/lib64


CPP0X_FLAG = -std=c++0x 
BOOST_REGEX = -lboost_regex

LIB_FLAGS = -lblas -llapack

OPT = -O2
## As the Armadillo library uses recursive templates, compilation times depend on the level of optimisation:
##
## -O0: quick compilation, but the resulting program will be slow
## -O1: good trade-off between compilation time and execution speed
## -O2: produces programs which have almost all possible speedups, but compilation takes longer
## -O3: enables auto vectorisation when using gcc

#EXTRA_OPT = -fwhole-program
## Uncomment the above line if you're compiling all source files into one program in a single hit


#DEBUG = -DARMA_EXTRA_DEBUG
## Uncomment the above line to enable low-level debugging.
## Lots of debugging information will be printed when a compiled program is run.
## Please enable this option when reporting bugs.


#FINAL = -DARMA_NO_DEBUG
## Uncomment the above line to disable Armadillo's checks.
## Not recommended unless your code has been first thoroughly tested!



CXXFLAGS = $(ARMA_INCLUDE_FLAG) $(DEBUG) $(FINAL) $(OPT) $(EXTRA_OPT)

all: main

arma:	armadilloexample.cpp
		   	$(CXX) $(CXXFLAGS) -o $@  $<  $(LIB_FLAGS)

boostclock0:	boostclock0.cpp
	$(CXX) $(BOOST_INCLUDE_FLAG) $(BOOST_LIB_FLAG) -o $@  $< $(CPP0X_FLAG)

boostclock1:	boostclock1.cpp
	$(CXX) $(BOOST_INCLUDE_FLAG) $(BOOST_LIB_FLAG) -o $@  $< $(CPP0X_FLAG)

boostposix:	boostposix.cpp
	$(CXX) $(BOOST_INCLUDE_FLAG) $(BOOST_LIB_FLAG) -o $@  $< $(CPP0X_FLAG)

boostiterator:	boostiterator.cpp
	$(CXX) $(BOOST_INCLUDE_FLAG) $(BOOST_LIB_FLAG) -o $@  $< $(CPP0X_FLAG)

boostregex:	boostregex.cpp
	$(CXX) $(BOOST_INCLUDE_FLAG) $(BOOST_LIB_FLAG) -o $@  $< $(BOOST_REGEX)



.PHONY: clean

armaclean: 
	rm -f arma A.txt *.*~ *~
	@echo "Clean done"

boostclean:
	rm -f boostclock0 boostclock1 boostposix boostiterator boostregex *~
	@echo "Clean done"


help:
	@echo "Please use \`make <target>' where <target> is one of"
	@echo " arma to compile armadillo example"
	@echo " boostclock0 to compile boost library clock0 example"
	@echo " boostclock1 to compile boost library clock1 example"
	@echo " boostposix to compile"
	@echo " boostiterator to compile"
	@echo " boostregex to compile"
	@echo " boostclean to clean bynaries"
	@echo " armaclean to remove binary and temporary files of the armadillo example"   


