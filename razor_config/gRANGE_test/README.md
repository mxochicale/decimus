
## Introduction

In the following test I change the saturation values of the Accelerometer
(+/- 2/4/8/16g) to test the range of each axis.
For the test, I put two sensor together and I move them as fast as I can in eightshape. In the following sections, I report the saturation values for
two imus (IMU_A and IMU_B).

Explore the path to see the graphical results. Also the raw data
for each test is available.

N.B. I use the Razor_Quaternion Firmware for the following tests

### Saturation at (+/- 2g); WIRE_SEND(0x31); WIRE_SEND(0x08);


          SATURATION
          index <- 12 #eightshape
          IMU_A and IMU_B ACC_X + ~500 saturation
          IMU_A and IMU_B ACC_Y +/- ~500 saturation
          IMU_A and IMU_B ACC_Z + ~500 saturation


### Saturation at (+/- 4g);  WIRE_SEND(0x31); WIRE_SEND(0x09);

    SATURATION
    index <- 12 #eightshape
    IMU_A ACC_Z
    IMU_B ACC_Z
    The saturation appears at values which are closer to 1100



### Saturation at (+/- 8g); WIRE_SEND(0x31); WIRE_SEND(0x10);

    index <- 12 #eightshape
    IMU_A and IMU_B ACC_X + ~500 saturation
    IMU_A and IMU_B ACC_Y - ~500 saturation
    IMU_A and IMU_B ACC_Z + ~500 saturation



### Saturation at (+/- 16g); WIRE_SEND(0x31); WIRE_SEND(0x11);

    index <- 12 #eightshape
    IMU_A and IMU_B ACC_X + ~500 saturation
    IMU_A and IMU_B ACC_Z + ~500 saturation


### Conclusion

I can conclude that the +/-4g saturation provides the less saturated values
which are only reflected on the Z axis of both sensors when
the persons performs the 8shape movement. Explore the directories for data
and the graphical results.
