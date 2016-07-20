
Accelerometer Min and Max calibration values @N310, Gisbert Kapp(G8)
====================================================================

Following [https://github.com/Tyrint/Razor-IMU/blob/master/Quaternion_Code_Final/Code%20Documentation.pdf](the instructions of Anthony Grace)




#osrt #o1 #o0
30 seconds of data


Calibrating the gyroscope values @N310, Gisbert Kapp(G8)
====================================================================
    Lay the Razor still on the table.  
    Wait for 30 seconds, and do not move the Razor. It will collect data from the gyroscope on all three axes.  


imu_0
---


```
Calibrating Accelerometer Using FTDI
Thu Jul 14 10:40:19 BST 2016

Values using the following axis orientation
__________________________
|o              +y        o|
|--             /\       * |
|  |        -x <  > +x   * |
|--             \/       * |
|               -y       * |
|o________________________o|


> source('~/github/decimus-dev/razor_config/Accelerometer_Calibration/acc_cal.R', echo=FALSE)
Filename: acc_x_neg.raw
mean AX  -288.508542713568
Filename: acc_x_plus.raw
mean AX  273.931677018634
Filename: acc_y_neg.raw
mean AY  279.964862298196
Filename: acc_y_plus.raw
mean AY  -276.723204994797
Filename: acc_z_neg.raw
mean AZ  -319.060217176703
Filename: acc_z_plus.raw
mean AZ  185.393309222423




Values using the following axis orientation
 __________________________
|o              +y        o|
|--             /\       * |
|  |        +x <  > -x   * |
|--             \/       * |
|               -y       * |
|o________________________o|


data for 30 seconds



> source('~/github/decimus-dev/razor_config/Accelerometer_Calibration/acc_cal.R', echo=FALSE)
Filename: acc_x_neg.raw
mean AX  -288.827493261456
Filename: acc_x_plus.raw
mean AX  274.882311977716
Filename: acc_y_neg.raw
mean AY  280.060200668896
Filename: acc_y_plus.raw
mean AY  -276.458776595745
Filename: acc_z_neg.raw
mean AZ  -319.087398373984
Filename: acc_z_plus.raw
mean AZ  185.381733021077




> source('~/github/decimus-dev/razor_config/ACC_GYR_Calibration/gyr_cal.R')
Filename: gyr_xyz.raw
mean GX  -28.6988823142669
mean GY  16.197896120973
mean GZ  15.9316239316239



```

```
##Uploaded values on Thu Jul 14 14:45:06 BST 2016

#define ACCEL_X_MIN ((float) -288)  
#define ACCEL_X_MAX ((float) 274)  
#define ACCEL_Y_MIN ((float) -276)  
#define ACCEL_Y_MAX ((float) 280)  
#define ACCEL_Z_MIN ((float) -319)  
#define ACCEL_Z_MAX ((float) 185)  


#define GYRO_AVERAGE_OFFSET_X ((float) -28.69)
#define GYRO_AVERAGE_OFFSET_Y ((float) 16.19)
#define GYRO_AVERAGE_OFFSET_Z ((float) 15.93)


```



imu_1
---

Star: Thu Jul 14 15:17:18 BST 2016




```

> source('~/github/decimus-dev/razor_config/Accelerometer_Calibration/acc_cal.R', echo=FALSE)
Filename: acc_x_neg.raw
mean AX  281.743623283192
Filename: acc_x_plus.raw
mean AX  -274.200517464424
Filename: acc_y_neg.raw
mean AY  280.747273893521
Filename: acc_y_plus.raw
mean AY  -267.404109589041
Filename: acc_z_neg.raw
mean AZ  -291.48329925017
Filename: acc_z_plus.raw
mean AZ  210.502310231023



> source('~/github/decimus-dev/razor_config/ACC_GYR_Calibration/gyr_cal.R')
Filename: gyr_xyz.raw
mean GX  -56.1238159675237
mean GY  41.7246278755074
mean GZ  -1.66305818673884


```

```
#define ACCEL_X_MIN ((float) -274)  
#define ACCEL_X_MAX ((float) 281)  
#define ACCEL_Y_MIN ((float) -267)  
#define ACCEL_Y_MAX ((float) 280)  
#define ACCEL_Z_MIN ((float) -291)  
#define ACCEL_Z_MAX ((float) 210)  

#define GYRO_AVERAGE_OFFSET_X ((float) -56.12)
#define GYRO_AVERAGE_OFFSET_Y ((float) 41.72)
#define GYRO_AVERAGE_OFFSET_Z ((float) -1.66)

```

Finish: Thu Jul 14 15:33:09 BST 2016





imu_2
---
Star: Thu Jul 14 15:37:26 BST 2016

```
> source('~/github/decimus-dev/razor_config/Accelerometer_Calibration/acc_cal.R', echo=FALSE)
Filename: acc_x_neg.raw
mean AX  277.814578005115
Filename: acc_x_plus.raw
mean AX  -277.189189189189
Filename: acc_y_neg.raw
mean AY  295.574424898511
Filename: acc_y_plus.raw
mean AY  -261.599737532808
Filename: acc_z_neg.raw
mean AZ  -305.060465116279
Filename: acc_z_plus.raw
mean AZ  200.658073270014

> source('~/github/decimus-dev/razor_config/ACC_GYR_Calibration/gyr_cal.R')
Filename: gyr_xyz.raw
mean GX  -9.6193724420191
mean GY  36.3083219645293
mean GZ  6.01637107776262
>

```

```



#define ACCEL_X_MIN ((float) -277)
#define ACCEL_X_MAX ((float) 277)
#define ACCEL_Y_MIN ((float) -261)
#define ACCEL_Y_MAX ((float) 295)
#define ACCEL_Z_MIN ((float) -305)
#define ACCEL_Z_MAX ((float) 200)

#define GYRO_AVERAGE_OFFSET_X ((float) -9.61)
#define GYRO_AVERAGE_OFFSET_Y ((float) 36.30)
#define GYRO_AVERAGE_OFFSET_Z ((float) 6.01)


```


Finish:Thu Jul 14 16:28:40 BST 2016








imu_3
---
Star: Thu Jul 14 16:38:19 BST 2016


```
> source('~/github/decimus-dev/razor_config/Accelerometer_Calibration/acc_cal.R', echo=FALSE)
Filename: acc_x_neg.raw
mean AX  272.61252446184
Filename: acc_x_plus.raw
mean AX  -283.950960901259
Filename: acc_y_neg.raw
mean AY  290.854891661195
Filename: acc_y_plus.raw
mean AY  -259.118655240606
Filename: acc_z_neg.raw
mean AZ  -288.894941634241
Filename: acc_z_plus.raw
mean AZ  200.736146095718



> source('~/github/decimus-dev/razor_config/ACC_GYR_Calibration/gyr_cal.R')
Filename: gyr_xyz.raw
mean GX  -32.5414473684211
mean GY  -11.3111842105263
mean GZ  -10.0348684210526


```


```
#define ACCEL_X_MIN ((float) -283)
#define ACCEL_X_MAX ((float) 272)
#define ACCEL_Y_MIN ((float) -259)
#define ACCEL_Y_MAX ((float) 290)
#define ACCEL_Z_MIN ((float) -288)
#define ACCEL_Z_MAX ((float) 200)

#define GYRO_AVERAGE_OFFSET_X ((float) -32.54)
#define GYRO_AVERAGE_OFFSET_Y ((float) -11.31)
#define GYRO_AVERAGE_OFFSET_Z ((float) -10.03)
```

Finish: Thu Jul 14 17:00:19 BST 2016













TODO
---

In the acc_cal.R, it might be useful to create a file that generate the following file
#define ACCEL_X_MIN ((float) -268)
#define ACCEL_X_MAX ((float) 254)
#define ACCEL_Y_MIN ((float) -255)
#define ACCEL_Y_MAX ((float) 247)
#define ACCEL_Z_MIN ((float) -269)
#define ACCEL_Z_MAX ((float) 238)



#define GYRO_AVERAGE_OFFSET_X ((float) -32.54)
#define GYRO_AVERAGE_OFFSET_Y ((float) -11.31)
#define GYRO_AVERAGE_OFFSET_Z ((float) -10.03)
