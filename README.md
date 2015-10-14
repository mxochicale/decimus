
1. Introduction
============================

decimius class has methods for saving data from accelerometer, magnetometer and gyroscope sensors 
as well as euler angles in cvs files from the [IMU razor-9dof](https://github.com/ptrbrtz/razor-9dof-ahrs). Additionally, decimus class has methods for time delay embedding theorem and 
PCA algorithms using [armadillo C++ linear algebra library](http://arma.sourceforge.net/).

Infos, updates, bug reports, contributions and feedback: https://github.com/mxochicale/decimus

CopyLeft (C) October 2015
Miguel Perez-Xochicale <perez.xochicale AT gmail.com>
Doctoral Researcher in Human-Robot Interaction
University of Birmigham, U.K. (2014-2017)


2. decimus repository 
============================

decimus repository contains 4 directories

lib_dependencies
---
testing_libs directory contains several examples to test armadillo and boost libraries compilation,
it also contains a README.md file for library installation.

src
---
It contains the source code project files:
main.cpp, Decimus.h, Decimus.cpp, RazorAHRS.h, RazorAHRS.cpp and Makefile.

prior to compile the project, set library paths in the Makefile 

```
$make 
```
to clean 
```
$make clean
```

Prior to run the application, it is recommended that you test the IMU sensor by using 
```
sudo miniterm.py -d /dev/rfcomm0 -b 9600
```

to run you should pair the bluetooth module [Section 3].


data
---
it has a test directory which has a cvs file as an example

r-code
---
contains an R source code to read and plot the data from an csv file using accelerometer, 
magnetometer and gyroscope data and euler angles.

3. Pairing bluetooth 
============================

It is recommended that you install blueman for pairing the bluetooh modules
Example Usage
--
* Scan the nearby bluetooth connections 

```
$ hcitool scan 
Scanning ...
00:18:B2:03:77:7B	Serial Port Device
```

* When a device has been discovered, l2ping is used to test the connection

```
$ sudo l2ping 00:18:B2:03:77:7B -c 2
Ping: 00:18:B2:03:77:7B from AC:xx:xx:xx:xx:xx (data size 44) ...
44 bytes from 00:18:B2:03:77:7B id 0 time 8.85ms
44 bytes from 00:18:B2:03:77:7B id 1 time 5.90ms
2 sent, 2 received, 0% loss
```

* Connect the device to rfcomm 0
```
$ sudo rfcomm connect 0 00:18:B2:03:77:7B
Connected /dev/rfcomm0 to 00:18:B2:03:77:7B on channel 1
Press CTRL-C for hangup

* Release the port
```
$ sudo rfcomm release 0
```


N bluetooth devices
--

In order to connect to N bluetooth devices automatically, 
a rfcomm.conf file should be created at 
"/etc/bluetooth/rfcomm.conf" contains the mac adresses of each device,
as the following example:

```
rfcomm0 {
        bind no;
        device 00:18:B2:03:77:7B;
        channel 1;
        comment "Serial Port";
        }
```

Then, simply run

```
$sudo rfcomm connect 0
```

Two Bluetooth Adapters
--

If you have more than 1 bluetooth hardware and would
like to use second one, use hciconfig to find adapter name and
then use that name in place of hci#. Command as below

```
$ sudo bluez-simple-agent hci# XX:XX:XX:XX:XX:XX
```

```
$ hcitool dev
Devices:
	hci1	00:30:91:10:00:26
	hci0	AC:72:89:A3:17:B7
```

References:
https://myraspberryandme.wordpress.com/2013/11/20/bluetooth-serial-communication-with-hc-05/



Download
---

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

8.1 Multiple Sensors
=====================

Expect is useful for running any program which requires interaction between the program and the user.
In Ubuntu multixterm included in expect package. Install expect in Ubuntu:

```
$sudo aptitude install expect
```


9. TODO List
=============

* Add instructions on how to compile the project using either kdevelop or makefile.
* When the project is compiled with make, a directory is create in the main root of the source code,
  it is therefore suggested to modify (check this English grammar rule) the Makefile project to create
  a build directory in src path.
* ADD logbook file to the README file to report issues
* PARTIALLY DONE: Check the methods at decimus class that save the values for 
  YAW_PITCH_ROLL, ACC_MAG_GYR_RAW, and ACC_MAG_GYR_CALIBRATED
* PARTIALLY DONE: Edit README.md from lib_dependencies
* PARTIALLY DONE: Check the R file comments and add another file for the euler angles


10. CHANGES
=============

* Oct 2015
  - creation of the r-code directory with the plots and function scripts.
  - added files for the kdevelop project in the src path	 
  - modification of the main README.md file



11. Release Notes
=============

0.1.1
-----
Wed Oct 14 09:21:17 BST 2015


0.1.0 
-----
Initial release. (Friday 22 May 2015)


