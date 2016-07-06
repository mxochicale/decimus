#!/bin/bash


#  Miguel Xochicale
#  Script for download, untar and install eigen library
#  chmod +x <filename>.sh



## TESTED ON
#-- Build string:      linux-3.13.0-91-generic-_-4.8.4-sse2-64bit
#-- Enabled backends:  Qt4 support,
# CXX_VERSION:       c++ (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4


lib_name=eigen
lib_version=3.2.8
extension=.tar.gz


cd
mkdir -p .lib_dependencies #mkdir: cannot create directory ‘.lib_dependencies’: File exists
cd .lib_dependencies
mkdir -p ${lib_name}-${lib_version}

echo "--------------------------------------------------------------"
echo "     EIGEN Library  <http://eigen.tuxfamily.org/index.php>    "
echo "--------------------------------------------------------------"

wget http://bitbucket.org/eigen/eigen/get/${lib_version}${extension} -O ${lib_name}-${lib_version}${extension}
tar -xzf ${lib_name}-${lib_version}${extension}
rm ${lib_name}-${lib_version}${extension}


#Method 2. Installing using CMake
#********************************


cd eigen-eigen-07105f7124f9
mkdir -p build_dir
cd build_dir
cmake ../ -DCMAKE_INSTALL_PREFIX=~/.lib_dependencies/${lib_name}-${lib_version}

#-- make install  | Install Eigen. Headers will be installed to:
#--               |     <CMAKE_INSTALL_PREFIX>/<INCLUDE_INSTALL_DIR>
#--               |   Using the following values:
#--               |     CMAKE_INSTALL_PREFIX: /usr/local
#--               |     INCLUDE_INSTALL_DIR:  include/eigen3
#--               |   Change the install location of Eigen headers using:
#--               |     cmake . -DCMAKE_INSTALL_PREFIX=yourprefix

sudo make install

echo "---------------------------"
echo "           done            "
echo "---------------------------"


#cd ~/.lib_dependencies/${lib_name}-${lib_version}
#CURRENT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
#echo "CURRENT_DIR is '$CURRENT_DIR'"
