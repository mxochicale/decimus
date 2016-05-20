

RAZOR CALIBRATION
==================



* For the RAZOR 9DOF calibration [Wed Dec 16 12:52:01 GMT 2015]

There is a dependency with EJML library


DOWNLOAD ejml-0.24 FROM
https://code.google.com/p/efficient-java-matrix-library/downloads/detail?name=ejml-0.24.jar  
rename ejml-0.24 to EJML.jar  
and copy in the  
~/sketchbook/libraries/EJML/library/EJML.jar


Libraries must be installed in a folder named 'libraries' inside the 'sketchbook' folder.
/home/map479-admin/sketchbook/libraries/EJML/library/
```
     Documents
           Processing
                 your sketch folders
                 libraries
                       theLibrary
                             examples
                             library
                                   theLibrary.jar
                             reference
                             src
```

reference
https://github.com/processing/processing/wiki/How-to-Install-a-Contributed-Library


* connect bluetooth module to /dev/rfcomm0
```
$ rfcomm -i hci0 connect 0
```

then, run Magnetomer_calibration.pde

```
#define CALIBRATION__MAGN_USE_EXTENDED true
const float magn_ellipsoid_center[3] = {-12.5370, 71.0733, 14.5352};
const float magn_ellipsoid_transform[3][3] = {{0.978492, -0.00889716, -0.0173017}, {-0.00889716, 0.967404, -0.000974981}, {-0.0173017, -0.000974981, 0.984761}};
```

For full instructions go to: https://github.com/ptrbrtz/razor-9dof-ahrs/wiki/Tutorial#standard-calibration



SENSOR CALIBRATION of RAZOR 9DOF at N310 Gisbert Kapp
========================================================

```
# Wed Dec 16 13:13:59 GMT 2015

//imu_ZERO
// Put MIN/MAX and OFFSET readings for your board here!
// Accelerometer
// "accel x,y,z (min/max) = X_MIN/X_MAX  Y_MIN/Y_MAX  Z_MIN/Z_MAX"
#define ACCEL_X_MIN ((float) -271)
#define ACCEL_X_MAX ((float) 252)
#define ACCEL_Y_MIN ((float) -252)
#define ACCEL_Y_MAX ((float) 254)
#define ACCEL_Z_MIN ((float) -285)
#define ACCEL_Z_MAX ((float) 233)


// Extended magn
#define CALIBRATION__MAGN_USE_EXTENDED true
const float magn_ellipsoid_center[3] = {-12.5370, 71.0733, 14.5352};
const float magn_ellipsoid_transform[3][3] = {{0.978492, -0.00889716, -0.0173017}, {-0.00889716, 0.967404, -0.000974981}, {-0.0173017, -0.000974981, 0.984761}};


// "gyro x,y,z (current/average) = .../OFFSET_X  .../OFFSET_Y  .../OFFSET_Z
#define GYRO_AVERAGE_OFFSET_X ((float) -24.5)
#define GYRO_AVERAGE_OFFSET_Y ((float) 17.24)
#define GYRO_AVERAGE_OFFSET_Z ((float) 15.22)
```





```
# Wed Dec 16 14:24:47 GMT 2015

// imu_ONE
// Put MIN/MAX and OFFSET readings for your board here!
// Accelerometer
// "accel x,y,z (min/max) = X_MIN/X_MAX  Y_MIN/Y_MAX  Z_MIN/Z_MAX"
#define ACCEL_X_MIN ((float) -268)
#define ACCEL_X_MAX ((float) 254)
#define ACCEL_Y_MIN ((float) -255)
#define ACCEL_Y_MAX ((float) 247)
#define ACCEL_Z_MIN ((float) -269)
#define ACCEL_Z_MAX ((float) 238)

#define CALIBRATION__MAGN_USE_EXTENDED true
const float magn_ellipsoid_center[3] = {-17.9313, 95.3543, 15.0557};
const float magn_ellipsoid_transform[3][3] = {{0.865366, -0.00140210, -0.0271258}, {-0.00140210, 0.870332, 0.00259720}, {-0.0271258, 0.00259720, 0.994471}};


// "gyro x,y,z (current/average) = .../OFFSET_X  .../OFFSET_Y  .../OFFSET_Z
#define GYRO_AVERAGE_OFFSET_X ((float) -57.78)
#define GYRO_AVERAGE_OFFSET_Y ((float) 45.38)
#define GYRO_AVERAGE_OFFSET_Z ((float) -2.04)

```




Arduino Micro Configuration
=====================


Arduino IDE : Select board "Arduino Pro or Pro Mini (3.3v, 8Mhz) w/ATmega328"

```
#define OUTPUT__STARTUP_STREAM_ON false // L192
#define HW__VERSION_CODE 10724 // L164 SparkFun "9DOF Sensor Stick" version "SEN-10724" (HMC5883L magnetometer)
```
For further instructions go to: [Razor Arduino](https://github.com/ptrbrtz/razor-9dof-ahrs/tree/master/Arduino)
