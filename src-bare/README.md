

Example of Usage
--

Compile test program:	
```
$ make
g++ -c Example.cpp -Wall -D_REENTRANT -lpthread
g++ -c RazorAHRS.cpp -Wall -D_REENTRANT -lpthread
g++ -o example Example.o RazorAHRS.o -Wall -D_REENTRANT -lpthread
```

Run it:
```
$ sudo ./example
```

Remember that you have to connect the bluetoth dongle to a port, for instance:
```
$ sudo rfcomm -i hci1 connect 0 00:06:66:71:5A:C6
Connected /dev/rfcomm0 to 00:06:66:71:5A:C6 on channel 1
Press CTRL-C for hangup
```

To remove executable and object files:
```
$ make clean
rm -f *.o *~ example
```


Source code has been tested on:
--
* Raspberry PI 3
```
$ date
Sat 23 Apr 01:13:35 BST 2016

$ lsb_release -a
No LSB modules are available.
Distributor ID:	Ubuntu
Description:	Ubuntu 16.04 LTS
Release:	16.04
Codename:	xenial

$ uname -a
Linux pi3-desktop 4.1.19-v7+ #858 SMP Tue Mar 15 15:56:00 GMT 2016 armv7l armv7l armv7l GNU/Linux
```


