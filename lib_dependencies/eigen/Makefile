fileinfo := Makefile to test EIGEN library
author := Miguel Xochicale



CXX=g++

LIB_DEP_PATH = ~/.lib_dependencies
lib_name=eigen
lib_version=3.2.8
EIGEN_INCLUDE_FLAG = -I ${LIB_DEP_PATH}/${lib_name}-${lib_version}/include/eigen3/


#CPP0X_FLAG = -std=c++0x
#LIB_FLAGS = -lblas -llapack
#CXXFLAGS = $(ARMA_INCLUDE_FLAG) $(DEBUG) $(FINAL) $(OPT) $(EXTRA_OPT)


all: eigen_a eigen_b

eigen_a:	my_program_a.cpp
	$(CXX) $< $(EIGEN_INCLUDE_FLAG) -o $@

eigen_b:	my_program_b.cpp
		$(CXX) $< $(EIGEN_INCLUDE_FLAG) -o $@


.PHONY: clean

clean:
	rm -f eigen_a eigen_b *.*~ *~
	@echo "Clean done :)"


help:
	@echo "Please use \`make <target>' where <target> is one of"
	@echo " eigen to compile eigen example"
	@echo " armaclean to remove binary and temporary files of the armadillo example"
