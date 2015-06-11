/*
                                                                                        
                88                          88                                              
                88                          ""                                              
                88                                                                          
        ,adPPYb,88   ,adPPYba,   ,adPPYba,  88  88,dPYba,,adPYba,   88       88  ,adPPYba,  
       a8"    `Y88  a8P_____88  a8"     ""  88  88P'   "88"    "8a  88       88  I8[    ""  
       8b       88  8PP"""""""  8b          88  88      88      88  88       88   `"Y8ba,   
       "8a,   ,d88  "8b,   ,aa  "8a,   ,aa  88  88      88      88  "8a,   ,a88  aa    ]8I  
        `"8bbdP"Y8   `"Ybbd8"'   `"Ybbd8"'  88  88      88      88   `"YbbdP'Y8  `"YbbdP"'[2]  
                                                                                            
                                                                                            
     D  time-Delay
     E  Embedding
     C  approaCh for     
     I  Inertial
     M  Measurment
     Us Units
  
  
    Introduction
    ------------
    decimius class is implemented with methods for saving data from
    accelerometer, magnetometer and gyroscope as well as euler angles 
    in cvs files. 
    Additionally, using the armadillo libarry, the decimus class has 
    methods for the time delay embedding and PCA for the state space 
    representation.
    decimius class is based on IMU razor-9dof class [1].
        
    
    References
    ----------
    [1] IMU razor-9dof application
    https://github.com/ptrbrtz/razor-9dof-ahrs    
    [2] decimus font title name: Univers 
    http://patorjk.com/software/taag/
    
    
    License
    -------
    CopyLeft (C) 2014 Miguel P. Xochicae
    perez[dot]xochicale[at]gmail[dot]com
    
    Infos, updates, bug reports, contributions and feedback:
    https://github.com/mxochicale/decimus
    
    
   */ 
  

#include <iostream>	// cout()
#include <iomanip>	// setprecision() etc.
#include <stdexcept>  	// runtime_error
#include <cstdio>     	// getchar()
#include "RazorAHRS.h" 	// IMU Razon 9DOF library
#include "Decimus.h"    // time-delay embedding and pca implementation
using namespace std;


const string serial_port_name = "/dev/rfcomm0"; 	// Set the serial port
std::string sensorname = "imu0"; 			// Set imu tag name

RazorAHRS *razor; 	// razor pointer Object
Decimus DataAnalysis;  	//DataAnalysis Object

//////////////////////////////////
// Razor error callback handler
// Will be called from (and in) Razor background thread!
void on_error(const string &msg)
{
  cout << "  " << "ERROR: " << msg << endl;
  
  // NOTE: make a copy of the message if you want to save it or send it to another thread. Do not
  // save or pass the reference itself, it will not be valid after this function returns! 
}

//////////////////////////////////
// Razor data callback handler
// Will be called from (and in) Razor background thread!
// 'data' depends on mode that was set when creating the RazorAHRS object. In this case 'data'
// holds 3 float values: yaw, pitch and roll.
void on_data(const float data[])
{  

  // NOTE: make a copy of the yaw/pitch/roll data if you want to save it or send it to another
  // thread. Do not save or pass the pointer itself, it will not be valid after this function
  // returns!
  
  // If you created the Razor object using RazorAHRS::ACC_MAG_GYR_RAW or RazorAHRS::ACC_MAG_GYR_CALIBRATED
  // instead of RazorAHRS::YAW_PITCH_ROLL, 'data' would contain 9 values that could be printed like this:
  

  // DataAnalysis.writedataYAWPITCHROLL(data[0] , data[1] , data[2]);
     DataAnalysis.writedataACCMAGGYR(data[0] , data[1] , data[2], data[3] , data[4], data[5], data[6] ,data[7] , data[8] );
}


int main(int argc, char *argv[])
{
  DataAnalysis.userpathname(argv[1]);
  
// RazorAHRS::Mode DataTypeMode = RazorAHRS::YAW_PITCH_ROLL;
   RazorAHRS::Mode DataTypeMode = RazorAHRS::ACC_MAG_GYR_CALIBRATED;
//   RazorAHRS::Mode DataTypeMode = RazorAHRS::ACC_MAG_GYR_RAW;
  
  DataAnalysis.sensor_number(sensorname);
 
// DataAnalysis.Set_SpaceReconstructionParameters(50,10,5); // (lengthwindowframe, dim, tau)
// DataAnalysis.Set_SpaceReconstructionParameters(200,20,5); // (lengthwindowframe, dim, tau)  
  
  if (DataTypeMode == 0) {DataAnalysis.SensorDataType(Decimus::YAW_PITCH_ROLL);}
  else if (DataTypeMode == 1) {DataAnalysis.SensorDataType(Decimus::ACC_MAG_GYR_RAW);}
  else {DataAnalysis.SensorDataType(Decimus::ACC_MAG_GYR_CALIBRATED);}

cout << endl;
cout << endl;
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
cout << "" << endl;
//							http://patorjk.com/software/taag/

cout << endl;
cout << endl;
cout << endl;    
cout << "                           Miguel Perez-Xochicale       " << endl;  
cout << endl;
cout << endl;
cout << endl;
cout << endl;

DataAnalysis.testingzone();
  
  cout << "  " << "Press RETURN to connect to tracker. When you're done press RETURN again to quit." << endl;
//   getchar();  // wait RETURN
//   cout << "  " << "Connecting..." << endl << endl;
  
  try
  {
    // Create Razor AHRS object. Serial I/O will run in background thread and report
    // errors and data updates using the callbacks on_data() and on_error().
    // We want to receive yaw/pitch/roll data. If we wanted the unprocessed raw or calibrated sensor
    // data, we would pass RazorAHRS::ACC_MAG_GYR_RAW or RazorAHRS::ACC_MAG_GYR_CALIBRATED
    // instead of RazorAHRS::YAW_PITCH_ROLL.
    
    
   razor = new RazorAHRS(serial_port_name, on_data, on_error, DataTypeMode);
   
     
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
  razor->_DISABLE_continuous_streaming_output();
      
  return 0;
}
