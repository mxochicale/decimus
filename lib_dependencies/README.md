=======
CHANGES
add how to use section and fixing the format of the README file
Tue Oct 13 10:05:46 BST 2015

Miguel Perez-Xochicale

# How to use

1. run setting_lib_dependencies.sh
2. cd testing_libs; change libraries paths on the Makefile
3. make help
Please use `make <target>' where <target> is one of
 arma to compile armadillo example
 boostclock0 to compile boost library clock0 example
 boostclock1 to compile boost library clock1 example
 boostposix to compile
 boostiterator to compile
 boostregex to compile
 boostclean to clean bynaries
 armaclean to remove binary and temporary files of the armadillo example
4. make <target>


# Library Dependencies 


In order to make a more portable source code for the IMU application, I suggest creating the 
following directories in the home path

```
$mkdir lib_dependencies
$cd lib_dependencies
```

to do so, you can run `setting_lib_dependecies.sh` script that runs automatically the below commands.



# ARMADILLO LIBRARY 
Downloading

```
$wget http://sourceforge.net/projects/arma/files/armadillo-5.100.1.tar.gz
$tar -xzf armadillo-5.100.1.tar.gz 
```

# BOOST LIBRARY

boost documentation 
[http://www.boost.org/doc/libs/1_58_0/more/getting_started/unix-variants.html]

1 Download boost_1_58_0.tar.bz2. [http://www.boost.org/users/history/version_1_58_0.html]
2 In the directory where you want to put the Boost installation, execute

```
wget http://downloads.sourceforge.net/project/boost/boost/1.58.0/boost_1_58_0.tar.bz2
$tar --bzip2 -xf boost_1_58_0.tar.bz2
$mkdir boost-1.58.0
$cd boost-1.58.0/
$mkdir lib64
```

```
$pwd 
~/lib_dependencies/boost-1.58.0
```

5.1   Easy Build and Install
Issue the following commands in the shell (don't type $; that represents the shell's prompt):

```
$ cd path/to/boost_1_58_0
$./bootstrap.sh --prefix=~/boost-1.58.0 --libdir=~/boost-1.58.0/lib64 
```

```
$./b2 -d+2 --layout=system variant=release link=shared threading=multi runtime-link=shared linkflags="-Wl,-rpath,~/boost-1.58.0/lib64" install
```
----for instance, installing on Ubuntu 14.04 LTS x64

$./bootstrap.sh --prefix=/home/map479/lib_dependencies/boost-1.58.0  --libdir=/home/map479/lib_dependencies/boost-1.58.0/lib64

$./b2 -d+2 --layout=system variant=release link=shared threading=multi runtime-link=shared linkflags="-Wl,-rpath,/home/map479/lib_dependencies/boost-1.58.0/lib64" install


ERROR 
======

```
# include <pyconfig.h>
                       ^
compilation terminated.
.
.
.
...failed updating 28 targets...
```

SOLUTION
http://stackoverflow.com/questions/8282231/ubuntu-i-have-python-but-gcc-cant-find-python-h

```
$sudo apt-get install python-dev 
```

will leave Boost binaries in the lib/ subdirectory of your installation prefix. 
You will also find a copy of the Boost headers in the include/ subdirectory of the installation prefix, 
so you can henceforth use that directory as an #include path in place of the Boost root directory.


