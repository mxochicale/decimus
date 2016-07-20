
Introduction
---
This path show three c++ applications to collect data from two razor imus.
Once you make the projects. You can only run
    $ ./kprojects nao2
or
using multixterm to run synchroniously
    $ ./kprojects nao2  
    $ ./kprojects nao2  


razorahrs
---

* lib dependencies  
  http://eigen.tuxfamily.org/index.php?title=Main_Page


* class dependencies
  RazorAHRS  


decimus and RazorAHRS
---

* lib dependencies  
  include_directories(~/.lib_dependencies/armadillo-5.100.1/include)  
  include_directories(~/.lib_dependencies/boost-1.58.0/include)  

* class dependencies
  Decimus  
  RazorAHRS  



NOTES
---


It is important to note that both approaches (one binary or two binaries) present a delayed synchronicity, i.e.
doing the same movement the data one of both sensors is delayed by N number of samples.
The delay between the two sensor samples is increasing as time goes higher.

I silly guessing that  the reason for that is an unknown delay when collecting the data from the threads.
I reckon it might be solved by doing some sort of hand shake
between sensor-machine at X time to avoid any delay between both sensors.
