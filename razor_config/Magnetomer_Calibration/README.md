

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






 SENSOR CALIBRATION of RAZOR 9DOF at N310 Gisbert Kapp
 ========================================================


 imu_ZERO
 ---


 ```
 # Wed Dec 16 13:13:59 GMT 2015

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
 Using bluetooth BlueSMiRF
 rfcomm connect 0  00:06:66:71:5C:D4

 Tue Jul 12 21:53:29 BST 2016

 #define CALIBRATION__MAGN_USE_EXTENDED true
 const float magn_ellipsoid_center[3] = {-20.4789, 110.672, 21.1607};
 const float magn_ellipsoid_transform[3][3] = {{0.946696, 0.0454603, 0.00358561}, {0.0454603, 0.932156, -0.0349348}, {0.00358561, -0.0349348, 0.964808}};

 ```



 imu_ONE
 ---

 ```
 # Wed Dec 16 14:24:47 GMT 2015

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

 ```
 rfcomm connect 0  00:06:66:71:5A:C6
 Tue Jul 12 22:02:01 BST 2016


 #define CALIBRATION__MAGN_USE_EXTENDED true
 const float magn_ellipsoid_center[3] = {-20.7501, 110.810, 9.81764};
 const float magn_ellipsoid_transform[3][3] = {{0.822359, -0.0137044, -0.0305710}, {-0.0137044, 0.882315, 0.00568446}, {-0.0305710, 0.00568446, 0.994184}};


 ```
