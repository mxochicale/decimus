!/bin/bash
#
#  chmod +x <filename>.sh
#  Thu Jun 11 15:03:42 BST 2015
#
#                        miguel [http://mxochicale.github.io]
#              Doctoral Researcher in Human-Robot Interaction
#                @ University of Birmingham, U.K. (2014-2018)
#------------------------------------------------------------


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
