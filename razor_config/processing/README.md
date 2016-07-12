

RAZOR MAGNETOMETER CALIBRATION
==================

* to run, go to and type:  
~/.processing/processing-3.0$ ./processing  


* connect bluetooth module to /dev/rfcomm0  

```
$ rfcomm -i hci0 connect 0
```

then, run Magnetomer_calibration.pde  on processing and follow the instructions on  
 https://github.com/ptrbrtz/razor-9dof-ahrs/wiki/Tutorial#standard-calibration
