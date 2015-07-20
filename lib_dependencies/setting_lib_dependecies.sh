#!/bin/bash
#
#  Miguel P. Xochicale
#  Script for downloand, untar and install armadillo and boost libraries
#  
#  Thu Jun 11 15:03:42 BST 2015
# chmod +x <filename>.sh


echo "-------------------------------"
echo "Armadillo Library"
echo "-------------------------------"
wget http://sourceforge.net/projects/arma/files/armadillo-5.100.1.tar.gz 
tar -xzf armadillo-5.100.1.tar.gz 
rm armadillo-5.100.1.tar.*

echo "-------------------------------"
echo "Boost Library"
echo "-------------------------------"
wget http://downloads.sourceforge.net/project/boost/boost/1.58.0/boost_1_58_0.tar.bz2
tar --bzip2 -xf boost_1_58_0.tar.bz2
rm boost_1_58_0.tar.*

#create boost directories for installation
mkdir boost-1.58.0 
cd boost-1.58.0/ 

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
echo "DIR is '$DIR'"

mkdir lib64
cd ..

cd boost_1_58_0/  
./bootstrap.sh --prefix=$DIR --libdir=$DIR/lib64 
./b2 -d+2 --layout=system variant=release link=shared threading=multi runtime-link=shared linkflags="-Wl,-rpath,$DIR/lib64" install


