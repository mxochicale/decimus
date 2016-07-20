

Arduino Micro Configuration
=====================


Arduino IDE : Select board "Arduino Pro or Pro Mini (3.3v, 8Mhz) w/ATmega328"

```
#define OUTPUT__STARTUP_STREAM_ON false // L192
#define HW__VERSION_CODE 10724 // L164 SparkFun "9DOF Sensor Stick" version "SEN-10724" (HMC5883L magnetometer)
```
For further instructions go to: [Razor Arduino](https://github.com/ptrbrtz/razor-9dof-ahrs/tree/master/Arduino)




Accelerometer Sensor Specification [ADXL345] AnalogDevices
==========================================================
Its high resolution (4 mg/LSB) enables measurement
of inclination changes less than 1.0°. Its high resolution (4 mg/LSB)
enables measurement of inclination changes less than 1.0°.

                                                                    Min   Typ   Max   Unit  
Sensitivity at XOUT, YOUT, ZOUT  +/-2, 10-bit or full resolution    232   256   286   LSB/g   
Scale Factor at XOUT, YOUT, ZOUT  +/-2, 10-bit or full resolution   3.5   3.9   4.3   mg/LSB   


0 g BIAS LEVEL Each axis   
0 g Output for XOUT, YOUT                   −150, +/-40, +150 mg  
0 g Output for ZOUT                         −250, +/-80, +250 mg  
0 g Offset vs. Temperature for x-, y-Axes         +/-0.8      mg/°C  
0 g Offset vs. Temperature for z-Axis             +/-4.5      mg/°C  


Register 0x31—DATA_FORMAT (Read/Write)  

FULL_RES Bit (D3)
When this bit is set to a value of 1, the device is in full resolution
mode, where the output resolution increases with the g range set
by the range bits to maintain a 4 mg/LSB scale factor.

D1 D0 (Range)
0 0  (+/- 2g)

//Arduino Configuration
Wire.beginTransmission(ACCEL_ADDRESS);
  WIRE_SEND(0x31);  // Data format register
  WIRE_SEND(0x08);  // Set to full resolution
  Wire.endTransmission();
  delay(5);


Wire.beginTransmission(ACCEL_ADDRESS);
WIRE_SEND(0x2C);  // Rate
WIRE_SEND(0x09);  // Set to 50Hz(25Hz bandwidth), normal operation
Wire.endTransmission();


Register 0x32 to Register 0x37—DATAX0, DATAX1,
DATAY0, DATAY1, DATAZ0, DATAZ1 (Read Only).

These six bytes (Register 0x32 to Register 0x37) are eight bits
each and hold the output data for each axis. R

//Arduino Configuration
Wire.beginTransmission(ACCEL_ADDRESS);
WIRE_SEND(0x32);  // Send address to read from
Wire.endTransmission();
Wire.beginTransmission(ACCEL_ADDRESS);
Wire.requestFrom(ACCEL_ADDRESS, 6);  // Request 6 bytes
while(Wire.available())  // ((Wire.available())&&(i<6))
{
  buff[i] = WIRE_RECEIVE();  // Read one byte
  i++;
}
Wire.endTransmission();



https://www.sparkfun.com/datasheets/Sensors/Accelerometer/ADXL345.pdf



Gyro Sensor Specification [ITG-3200] IvenSense
==============================================

Characteristics
---

Gyro Sensitivity          Conditions  Typical   Unit    
Full-Scale Range          FS_SEL=3    +/-2000   o/s   
Gyro ADC Word Lenght                  16        Bits    
Sensitivity Scale Factor  FS_SEL=3    14.375   LSB/(o/s)

//Arduino Configuration
Wire.beginTransmission(GYRO_ADDRESS);  
WIRE_SEND(0x16);  
WIRE_SEND(0x1B);  // DLPF_CFG = 3 (42Hz), FS_SEL = 3 (+/-2000  o/s   )  
Wire.endTransmission();  



Registers 0x1D to 0x22 – Sensor Registers
---
GYRO_XOUT_H/L 16-bit  X gyro output data (2’s complement format)
GYRO_YOUT_H/L 16-bit  Y gyro output data (2’s complement format)
GYRO_ZOUT_H/L 16-bit  Y gyro output data (2’s complement format)

//Arduino Configuration
Wire.beginTransmission(GYRO_ADDRESS);
WIRE_SEND(0x1D);  // Sends address to read from
Wire.endTransmission();

Wire.beginTransmission(GYRO_ADDRESS);
Wire.requestFrom(GYRO_ADDRESS, 6);  // Request 6 bytes
while(Wire.available())  // ((Wire.available())&&(i<6))
{
  buff[i] = WIRE_RECEIVE();  // Read one byte
  i++;
}
Wire.endTransmission();


https://www.sparkfun.com/datasheets/Sensors/Gyro/PS-ITG-3200-00-01.4.pdf



Magnetometer Sensor Specification [HMC5883L] HoneyWell
======================================================



0x02 Mode Register
---

Wire.beginTransmission(MAGN_ADDRESS);
WIRE_SEND(0x02);
WIRE_SEND(0x00);  // Set continuous mode (default 10Hz)
Wire.endTransmission();


MD1 MD0 Operating Mode
 0  0  

In continuous-measurement mode, the device continuously performs measurements
and places the result in the data register. RDY goes high when new data is placed
in all three registers.  After a power-on or a write to the mode or
configuration register, the first measurement set is available from all
three data output registers after a period of 2/fDO and subsequent
measurements are available at a frequency of fDO, where fDO is the
frequency of data output


0x01 Configuration Register B
---

The configuration register B for setting the device gain.

GN2 GN1 GN0   Recommended Sensor Field Range  Gain(LSb/Gauss)   Digital Resolution (mG/LSb)    Output Range   
0 0 1         +/-1.3Ga                        1090 (default)    0.92                            0xF800–0x07FF(-2048–2047)   

The “Digital Resolution”  column  is  the  theoretical  value  in  term  of  milli-Gauss  per count (LSb)
which  is  the  inverse  of  the values in the “Gain” column. The effective resolution of the usable
signal also depends on the noise floor of the system, i.e.
Effective Resolution = Max (Digital Resolution, Noise Floor)




0x00 Configuration Register A
---

Data Output Rate Bits (CRA4, CRA3, CRA2).
These bits set the rate at which data is written to all three data output registers
The  Table  below  shows all  selectable output  rates in  continuous  measurement  mode.

DO2 DO1 DO0   Typical  Data Output Rate (Hz)
0 0 0         0.75
0 0 1         1.5
0 1 0         3
0 1 1         7.5



Wire.beginTransmission(MAGN_ADDRESS);
WIRE_SEND(0x00);
WIRE_SEND(0b00011000);  // Set 50Hz
Wire.endTransmission();


0x03 to 0x08 Data Output
---

0x03 X MSB Register
0x04 X LSB Register
0x05 Y MSB Register
0x06 Y LSB Register
0x07 Z MSB Register
0x08 Z LSB Register


Wire.beginTransmission(MAGN_ADDRESS);
WIRE_SEND(0x03);  // Send address to read from
Wire.endTransmission();

  Wire.beginTransmission(MAGN_ADDRESS);
  Wire.requestFrom(MAGN_ADDRESS, 6);  // Request 6 bytes
  while(Wire.available())  // ((Wire.available())&&(i<6))
  {
    buff[i] = WIRE_RECEIVE();  // Read one byte
    i++;
  }
  Wire.endTransmission();



http://cdn.sparkfun.com/datasheets/Sensors/Magneto/HMC5883L-FDS.pdf
