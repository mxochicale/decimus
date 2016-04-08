1. Introduction
============================

decimius is a C++ class which has methods to save data from
[IMU razor-9dof](https://github.com/ptrbrtz/razor-9dof-ahrs).
Additionally, decimus class has methods to run some linear algebra operations such as PCA using
[armadillo C++ linear algebra library](http://arma.sourceforge.net/).

> Miguel Xochicale <http://mxochicale.github.io>,  
> Doctoral Researcher in Human-Robot Interaction,  
> University of Birmingham, U.K. (2014-2017)  

2. decimus repository
============================

2.1 bluetooth
---
bluetooth contains useful information to configure the dongles, linux machine and some commands

2.2 data
---
data contains a test directory which has data from the sensor in a cvs file.

2.3 lib_dependencies
---
testing_libs directory contains several examples to test armadillo
and boost libraries. It also contains a README.md file for library installation.

2.4 r-code
---
r-code contains R source code to read and plot the data from an csv file.

2.5 razor_calibration
---
razor_calibration contains library dependencies, commands and previous calibration values
for the razor sensor.

2.6 src
---
src contains the source code project files:
Make Project: main.cpp, Decimus.h, Decimus.cpp, RazorAHRS.h, RazorAHRS.cpp and Makefile.
Kdevelop Project: CMakeList.txt, src-kproject.kdev4


3. Download
=====================

download the source with your preferred method and install manually.

Using Git::
```
$ git clone https://github.com/mxochicale/decimus.git
$ cd decimus
```

Or wget::

```
   $ wget https://github.com/mxochicale/decimus/archive/master.zip
   $ unzip master.zip
   $ cd decimus-master
```



4. Issues
==============

NOTA BENE.
imus with bluetooth modules were programed using a speed of speed_t speed = B57600
around 1600 samples were collected in 60 seconds
and also using speed_t speed = B9600
give around 1600 samples in 60 seconds



* Sat Dec 12 20:11:53 GMT 2015
when recording data for 60 seconds the produded file is only around 1600 samples
which is different from what do we expect according the 50Hz sampling frequency.

To investigate the possible reason, razor has been connected using the
 FT232R USB UART at 9600bps;
however when setting 57600bps the monitor data does not present any data

What to test next?

* check whether using 57600 with the FT231R gives the correct samples.
* Mon Dec 14 11:44:14 GMT 2015

a bound rate of 57600 has been set in the razor sensor using arduino IDE
then the c++ application has been configurated as well so as to use /dev/ttyUSB0
and the set "speed_t speed = B57600"

Then data was collected during 60 seconds and this time around 2900 samples
were optained which is more acceptable considering that the sampling rate of
50 Hz should have 3000 samples.

* change the baudrate of the ARF7044A bluetooth modules to 57600
  -- ARF7044 works on windows with an application called blue smart.
     waiting for the technical support (# Tue Dec 15 15:31:05 GMT 2015)
     so as to connect bluetooth dongle



* Tue Dec 15 16:03:41 GMT 2015
We are now using the BlueSMiRF bluetooth module at 57600.
Remember that you have to change the baud rate speed in the razor board to match tha same
baud rate (57600)
```
#define OUTPUT__BAUD_RATE 57600 #line 171 Razor_AHRS.ino
```


5. TO DO List
=============

* When the project is compiled with make, a directory is create in the main root of the
  source code, it is therefore suggested to modify.
  (the Makefile project to create a build directory in src path.)
* PARTIALLY DONE: Check the methods at decimus class that save the values for
  YAW_PITCH_ROLL, ACC_MAG_GYR_RAW, and ACC_MAG_GYR_CALIBRATED
* Check the R file comments and add another file for the euler angles
* DIRECTORY DEVELOPMENT DESCRIPTION  Fri Feb 12 12:30:36 GMT 2016
src_getonesample # project that use #f to get one sample  
src_twosensors00 # project that can read two razor sensors  
src_twosensors01 # project that has been changed to work with one sensor  
src_twosensors** got the decimus class which should be merged with RazorAHRS  
