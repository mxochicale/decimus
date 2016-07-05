

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
* Raspberry PI 3 -- Ubuntu-mate
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

* Raspberry PI 3 -- Raspbian jessie

  $ Mon 25 Apr 20:17:26 UTC 2016  

  $ lsb_release -a  
  No LSB modules are available.  
  Distributor ID:	Raspbian  
  Description:	Raspbian GNU/Linux 8.0 (jessie)  
  Release:	8.0  
  Codename:	jessie  

  $  uname -a  Linux raspberrypi 4.1.19-v7+ #858 SMP Tue Mar 15 15:56:00 GMT 2016 armv7l GNU/Linux



  * 	Ubuntu 14.04.3 LTS x86_64

    $ date  
    Tue Jul  5 17:04:10 BST 2016  

    $ lsb_release -a  
    Distributor ID:	Ubuntu  
    Description:	Ubuntu 14.04.3 LTS  
    Release:	14.04  
    Codename:	trusty  

    $  uname -a  
    Linux eee320 3.13.0-91-generic #138-Ubuntu SMP Fri Jun 24 17:00:34 UTC 2016 x86_64 x86_64 x86_64 GNU/Linux  
