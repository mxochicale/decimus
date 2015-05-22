
$ mkdir lib_dependencies
$ cd lib_dependencies



ARMADILLO
Downloading

$wget http://sourceforge.net/projects/arma/files/armadillo-5.100.1.tar.gz
$tar -xzf armadillo-5.100.1.tar.gz 

INSTALLING BOOST

boost documentation 
[http://www.boost.org/doc/libs/1_58_0/more/getting_started/unix-variants.html]


wget http://downloads.sourceforge.net/project/boost/boost/1.58.0/boost_1_58_0.tar.bz2

1 Download boost_1_58_0.tar.bz2. [http://www.boost.org/users/history/version_1_58_0.html]
2 In the directory where you want to put the Boost installation, execute
$tar --bzip2 -xf boost_1_58_0.tar.bz2

$mkdir boost-1.58.0
$cd boost-1.58.0/
$pwd 
/home/map479/Downloads/temporal/github_imu/debian_machine/lib_dependencies/boost-1.58.0

5.1   Easy Build and Install
Issue the following commands in the shell (don't type $; that represents the shell's prompt):
$ cd path/to/boost_1_58_0
$ ./bootstrap.sh --help


You'll probably want to at least use to install somewhere else.

	>>>Debian machine
$./bootstrap.sh -prefix=/home/map479/Downloads/temporal/github_imu/debian_machine/lib_dependencies/boost-1.58.0 --libdir=/home/map479/Downloads/temporal/github_imu/debian_machine/lib_dependencies/boost-1.58.0/lib64

Unicode/ICU support for Boost.Regex?... not found.

$./b2 -d+2 --layout=system variant=release link=shared threading=multi runtime-link=shared linkflags="-Wl,-rpath,/home/map479/Downloads/temporal/github_imu/debian_machine/lib_dependencies/boost-1.58.0/lib64" install

	>>>Ubuntu machine
$./bootstrap.sh --prefix=/home/map479/Desktop --libdir=/home/map479/Desktop/lib64 
$./b2 -d+2 --layout=system variant=release link=shared threading=multi runtime-link=shared linkflags="-Wl,-rpath,/home/map479/Desktop/lib64" install

#$ sudo ./b2 -d+2 --layout=system variant=release link=shared threading=multi runtime-link=shared linkflags="-Wl,-rpath,/home/map479/Desktop/lib64" install
#$      ./b2 -d+2 --layout=system variant=release link=shared threading=multi runtime-link=shared linkflags="-Wl,-rpath,${PREFIX}/lib64"
#$ sudo ./b2 -d+2 --layout=system variant=release link=shared threading=multi runtime-link=shared linkflags="-Wl,-rpath,${PREFIX}/lib64" install

Finally,
#$ ./b2 install
will leave Boost binaries in the lib/ subdirectory of your installation prefix. 
You will also find a copy of the Boost headers in the include/ subdirectory of the installation prefix, 
so you can henceforth use that directory as an #include path in place of the Boost root directory.














