!/bin/bash
#
#  Miguel Perez-Xochicale
#  Script for download, untar and install processing
#
#  Thu Jun 11 15:03:42 BST 2015
#  chmod +x <filename>.sh

cd
mkdir .processing
cd .processing

VERSION=3.1.1-linux64

echo "-------------------------------"
echo "download processing"
echo "-------------------------------"
wget http://download.processing.org/processing-$VERSION.tgz
tar -xvf processing-$VERSION.tgz
rm processing-$VERSION.tgz

echo "-------------------------------"
echo "download EJML.jar dependencies in ~/sketchbook/libraries/EJML/library/"
echo "-------------------------------"

cd
mkdir -p sketchbook
cd sketchbook
mkdir -p libraries
cd libraries
mkdir -p EJML
cd EJML
mkdir -p library
cd library
wget -O EJML.jar https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/efficient-java-matrix-library/ejml-0.24.jar


#TODO create a launcher
