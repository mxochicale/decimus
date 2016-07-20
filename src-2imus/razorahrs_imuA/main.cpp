/******************************************************************************************
* Test Program: Mac OSX / Unix / Linux C++ Interface for Razor AHRS v1.4.2
* 9 Degree of Measurement Attitude and Heading Reference System
* for Sparkfun "9DOF Razor IMU" and "9DOF Sensor Stick"
*
* Released under GNU GPL (General Public License) v3.0
* Copyright (C) 2013 Peter Bartz [http://ptrbrtz.net]
* Copyright (C) 2011-2012 Quality & Usability Lab, Deutsche Telekom Laboratories, TU Berlin
* Written by Peter Bartz (peter-bartz@gmx.de)
*
* Infos, updates, bug reports, contributions and feedback:
*     https://github.com/ptrbrtz/razor-9dof-ahrs
******************************************************************************************/


#include "RazorAHRS.h"



// Set your serial port here!
//const string serial_port_name = "/dev/tty.FireFly-6162-SPP"; 
//const string serial_port_name = "/dev/tty.usbserial-A700eEhN";
//const string serial_port_name = "/dev/ttyUSB0"; // a good guess on linux

// const string serial_port_name_0 = "/dev/rfcomm0"; // bluetooth  serial port
// std::string sensorname_imu0 = "imu0"; 		// Set imu tag name
// RazorAHRS *razor_0; 	//razor pointer Object


std::string sensorname_imuA = "imu2"; 		// Set imu tag name
const string serial_port_name_A = "/dev/rfcomm0"; // bluetooth  serial port
RazorAHRS *razor_A; 	//razor pointer Object




// Razor error callback handler
// Will be called from (and in) Razor background thread!
void on_error(const string &msg)
{
  cout << "  " << "ERROR: " << msg << endl;
  
  // NOTE: make a copy of the message if you want to save it or send it to another thread. Do not
  // save or pass the reference itself, it will not be valid after this function returns! 
}

// // Razor data callback handler
// // Will be called from (and in) Razor background thread!
// // 'data' depends on mode that was set when creating the RazorAHRS object. In this case 'data'
// // holds 3 float values: yaw, pitch and roll.
// void on_data(const float data[])
// {
//   //**//cout << "  " << fixed << setprecision(1) 
//   //**//<< "Yaw = " << setw(6) << data[0] << "      Pitch = " << setw(6) << data[1] << "      Roll = " << setw(6) << data[2] << endl;
// 
//   // NOTE: make a copy of the yaw/pitch/roll data if you want to save it or send it to another
//   // thread. Do not save or pass the pointer itself, it will not be valid after this function
//   // returns!
//   
//   // If you created the Razor object using RazorAHRS::ACC_MAG_GYR_RAW or RazorAHRS::ACC_MAG_GYR_CALIBRATED
//   // instead of RazorAHRS::YAW_PITCH_ROLL, 'data' would contain 9 values that could be printed like this:
//   
//   // cout << "  " << fixed << setprecision(1)
//   // << "ACC = " << setw(6) << data[0] << ", " << setw(6) << data[1] << ", " << setw(6) << data[2]
//   // << "       MAG = " << setw(7) << data[3] << ", " << setw(7) << data[4] << ", " << setw(7) << data[5]
//   // << "       GYR = " << setw(7) << data[6] << ", " << setw(7) << data[7] << ", " << setw(7) << data[8] << endl;
// 
// }


void on_data_A(const float data[])
{
  
//    cout << "  " << fixed << setprecision(1) 
//    << "ZERO Yaw = " << setw(6) << data[0] << "      Pitch = " << setw(6) << data[1] << "      Roll = " << setw(6) << data[2] << endl;
  
}



//int main()
int main(int argc, char *argv[])
{
  
  
  cout << endl;
  cout << "  " << "Razor AHRS C++ test" << endl;
  cout << "  " << "Press RETURN to connect to tracker. When you're done press RETURN again to quit." << endl;
  getchar();  // wait RETURN
  cout << "  " << "Connecting..." << endl << endl;
  
  try
  {
    // Create Razor AHRS object. Serial I/O will run in background thread and report
    // errors and data updates using the callbacks on_data() and on_error().
    // We want to receive yaw/pitch/roll data. If we wanted the unprocessed raw or calibrated sensor
    // data, we would pass RazorAHRS::ACC_MAG_GYR_RAW or RazorAHRS::ACC_MAG_GYR_CALIBRATED
    // instead of RazorAHRS::YAW_PITCH_ROLL.
    //razor = new RazorAHRS(serial_port_name_0, on_data, on_error, RazorAHRS::YAW_PITCH_ROLL);
    
   
    razor_A = new RazorAHRS(serial_port_name_A, on_data_A, on_error, RazorAHRS::ACC_MAG_GYR_CALIBRATED, sensorname_imuA, argv[1]);
    
   
    
    // NOTE: If these callback functions were members of a class and not global
    // functions, you would have to bind them before passing. Like this:
    
    // class Callback
    // {
    //   public:
    //     void on_data(const float ypr[]) { }
    //     void on_error(const string &msg) { }
    // };
    
    // Callback c;
    
    // razor = new RazorAHRS(serial_port_name,
    //    bind(&Callback::on_data, &c, placeholders::_1),
    //    bind(&Callback::on_error, &c, placeholders::_1),
    //    RazorAHRS::YAW_PITCH_ROLL);
    
    // If you're calling from inside of "c" you would of course use "this" instead of "&c".
  }
  catch(runtime_error &e)
  {
    cout << "  " << (string("Could not create tracker: ") + string(e.what())) << endl;
    cout << "  " << "Did you set your serial port in Example.cpp?" << endl;
    return 0;
  }
  
  getchar();  // wait for RETURN key
  
 
  razor_A -> disable_continuous_streaming_output();
  
  
  return 0;
}

