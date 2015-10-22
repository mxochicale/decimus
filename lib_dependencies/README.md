How to install library dependencies
=======

> Miguel Perez-Xochicale <perez.xochicale AT gmail.com>,
> Doctoral Researcher in Human-Robot Interaction,
> University of Birmingham, U.K. (2014-2017)


TODO

[*] reorganise readme file # Thu Oct 22 18:14:19 BST 2015
[OK] add how to use section and fixing the format of the README file
Tue Oct 13 10:05:46 BST 2015


# Install Library Dependencies 

On Ubuntu 14.04.3 LTS x64, python-dev is installed by default

```
sudo apt-get install python-dev
```

Run `setting_lib_dependecies.sh` script that runs automatically the below commands.
```
./setting_lib_dependecies.sh
```

```
cd
mkdir .lib_dependencies
cd .lib_dependencies
# ARMADILLO LIBRARY Downloading
# BOOST LIBRARY
```

# How to use

```
cd lib_dependencies/testing_libs  #change libraries paths on the Makefile
```

```
make help
Please use `make <target>' where <target> is one of
 arma to compile armadillo example
 boostclock0 to compile boost library clock0 example
 boostclock1 to compile boost library clock1 example
 boostposix to compile
 boostiterator to compile
 boostregex to compile
 boostclean to clean bynaries
 armaclean to remove binary and temporary files of the armadillo example
```

```
make <target>
```


boost documentation 
[http://www.boost.org/doc/libs/1_58_0/more/getting_started/unix-variants.html]



### COMILATION ERRORS

```
# include <pyconfig.h>
                       ^
compilation terminated.
.
.
.
...failed updating 28 targets...
```

#### SOLUTION
http://stackoverflow.com/questions/8282231/ubuntu-i-have-python-but-gcc-cant-find-python-h

```
$sudo apt-get install python-dev 
```

will leave Boost binaries in the lib/ subdirectory of your installation prefix. 
You will also find a copy of the Boost headers in the include/ subdirectory of the installation prefix, 
so you can henceforth use that directory as an #include path in place of the Boost root directory.
