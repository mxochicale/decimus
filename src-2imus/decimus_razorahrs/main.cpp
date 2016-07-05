/******************************************************************************************
    
    decimius class has methods for saving data from
    accelerometer, magnetometer and gyroscope sensors as well as 
    euler angles in cvs files from the IMU razor-9dof [1].      
    Additionally, decimus class has methods for the time delay embedding 
    and PCA algorithms.
  
    References
    ----------
    [1] IMU razor-9dof application
    https://github.com/ptrbrtz/razor-9dof-ahrs    
    
    License
    -------
    CopyLeft (C) October 2015 Miguel Perez-Xochicae
    perez[dot]xochicale[at]gmail[dot]com
    
    Infos, updates, bug reports, contributions and feedback:
    https://github.com/mxochicale/decimus
    
    
    How to use?
    Comment either the first or the second block of lines so as to choose between 
    types of data from the IMU
    
    DataAnalysis.writeYAWPITCHROLL(data[0] , data[1] , data[2]);
    DataAnalysis.writeACCMAGGYR(data[0] , data[1] , data[2], data[3] , data[4], data[5], data[6] ,data[7] , data[8] );

    RazorAHRS::Mode DataTypeMode = RazorAHRS::YAW_PITCH_ROLL;
    RazorAHRS::Mode DataTypeMode = RazorAHRS::ACC_MAG_GYR_CALIBRATED;
    RazorAHRS::Mode DataTypeMode = RazorAHRS::ACC_MAG_GYR_RAW;

    
******************************************************************************************/

#include <iostream>   // cout()
#include <iomanip>    // setprecision() etc.
#include <stdexcept>  // runtime_error
#include <cstdio>     // getchar()
#include "RazorAHRS.h"

#include "Decimus.h"    // time-delay embedding and pca implementation
using namespace std;


// Set your serial port here!

const string serial_port_name_0 = "/dev/rfcomm0"; // bluetooth  serial port
const string serial_port_name_1 = "/dev/rfcomm1"; // bluetooth  serial port

std::string sensorname_imu0 = "imu0"; 		// Set imu tag name
std::string sensorname_imu1 = "imu1"; 		// Set imu tag name

RazorAHRS *razor_0; 	//razor pointer Object
RazorAHRS *razor_1; 	//razor pointer Object

Decimus DataAnalysis_0;  	//DataAnalysis Object
Decimus DataAnalysis_1;  	//DataAnalysis Object


// Razor error callback handler
// Will be called from (and in) Razor background thread!
void on_error(const string &msg)
{
  cout << "  " << "ERROR: " << msg << endl;
  
  // NOTE: make a copy of the message if you want to save it or send it to another thread. Do not
  // save or pass the reference itself, it will not be valid after this function returns! 
}



// Razor data callback handler will be called from (and in) Razor background thread!
// 'data' depends on mode that was set when creating the RazorAHRS object. 
void on_data_0(const float data[])
{

//  DataAnalysis.writeYAWPITCHROLL(data[0] , data[1] , data[2]);
    DataAnalysis_0.writeACCMAGGYR(data[0] , data[1] , data[2], data[3] , data[4], data[5], data[6] ,data[7] , data[8] );
//   DataAnalysis.printACCMAGGYR(data[0] , data[1] , data[2], data[3] , data[4], data[5], data[6] ,data[7] , data[8] );
}

// Razor data callback handler will be called from (and in) Razor background thread!
// 'data' depends on mode that was set when creating the RazorAHRS object. 
void on_data_1(const float data[])
{

//  DataAnalysis.writeYAWPITCHROLL(data[0] , data[1] , data[2]);
    DataAnalysis_1.writeACCMAGGYR(data[0] , data[1] , data[2], data[3] , data[4], data[5], data[6] ,data[7] , data[8] );
//   DataAnalysis.printACCMAGGYR(data[0] , data[1] , data[2], data[3] , data[4], data[5], data[6] ,data[7] , data[8] );
}


int main(int argc, char *argv[])
{

//######################################################
    DataAnalysis_0.userpathname(argv[1]);
    DataAnalysis_0.sensor_number(sensorname_imu0);
    DataAnalysis_1.userpathname(argv[1]);
    DataAnalysis_1.sensor_number(sensorname_imu1);
//######################################################
    
    
    cout << endl;
    cout << endl;
    cout << "          88                       88                                           " << endl;
    cout << "          88                       ""                                           " << endl;
    cout << "          88                                                                    " << endl;
    cout << "  ,adPPYb,88  ,adPPYba,  ,adPPYba, 88 88,dPYba,,adPYba,  88       88 ,adPPYba,  " << endl;
    cout << " a8'    `Y88 a8P_____88 a8'     '' 88 88P'   '88'    '8a 88       88 I8[    ''  " << endl;
    cout << " 8b       88 8PP''''''' 8b         88 88      88      88 88       88  `'Y8ba,   " << endl;
    cout << " '8a,   ,d88 '8b,   ,aa '8a,   ,aa 88 88      88      88 '8a,   ,a88 aa    ]8I  " << endl;
    cout << "  `'8bbdP'Y8  `'Ybbd8''  `'Ybbd8'' 88 88      88      88  `'YbbdP'Y8 `'YbbdP''  " << endl;
    cout << "" << endl; //http://patorjk.com/software/taag/
    cout << endl;
    cout << endl;    
    cout << "                           Miguel Perez-Xochicale       " << endl;  
    cout << endl;
    cout << endl;
  
    
    cout << endl;
    cout << endl;
    cout << "  " << "Press RETURN to connect to tracker. When you're done press RETURN again to quit." << endl;
    cout << endl;
    cout << endl;
    getchar();  // wait RETURN
   
    
    
// //    RazorAHRS::Mode DataTypeMode = RazorAHRS::YAW_PITCH_ROLL;
//      RazorAHRS::Mode DataTypeMode = RazorAHRS::ACC_MAG_GYR_CALIBRATED;
// //     RazorAHRS::Mode DataTypeMode = RazorAHRS::ACC_MAG_GYR_RAW;
//        
//     if (DataTypeMode == 0) {DataAnalysis.SensorDataType(Decimus::YAW_PITCH_ROLL);}
//     else if (DataTypeMode == 1) {DataAnalysis.SensorDataType(Decimus::ACC_MAG_GYR_RAW);}
//     else {DataAnalysis.SensorDataType(Decimus::ACC_MAG_GYR_CALIBRATED);}
// 

  
  try
  {
    // Create Razor AHRS object. Serial I/O will run in background thread and report
    // errors and data updates using the callbacks on_data() and on_error().

    
    
//######################################################
    razor_0 = new RazorAHRS(serial_port_name_0, on_data_0, on_error, RazorAHRS::ACC_MAG_GYR_CALIBRATED);
    razor_1 = new RazorAHRS(serial_port_name_1, on_data_1, on_error, RazorAHRS::ACC_MAG_GYR_CALIBRATED);
//######################################################
    
    

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
  
//######################################################
  razor_0 -> disable_continuous_streaming_output();
  razor_1 -> disable_continuous_streaming_output();
//######################################################
  
  
  return 0;
}
