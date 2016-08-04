# How to install library dependencies




## Install Library Dependencies

On Ubuntu 14.04.3 LTS x64, python-dev is installed by default.
However, for other versions you have to install it by runnning
the following command

```
sudo apt-get install python-dev
```

Run `setting_lib_dependecies.sh` script that runs automatically the below commands.
```
./setting_lib_dependecies.sh
```

## Testing libraries

```
cd lib_dependencies/testing_libs  
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

## References

* boost documentation
[http://www.boost.org/doc/libs/1_58_0/more/getting_started/unix-variants.html]

* python-dev COMILATION ERRORS
http://stackoverflow.com/questions/8282231/ubuntu-i-have-python-but-gcc-cant-find-python-h
