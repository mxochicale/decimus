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
    
******************************************************************************************/


#ifndef DECIMUS_H
#define DECIMUS_H

#include <time.h>	// time_t, struct tm, time, localtime, strftime 
#include <cstring>	// To use strcpy
#include <string>       // .c_str() -- Get C string equivalent 
                        // Returns a pointer to an array that contains 
                        // a null-terminated sequence of characters 
                        // (i.e., a C-string) representing the current value of the string object.

#include <stdlib.h>	//realpath("../", NULL);
#include <sys/types.h> 	//to create a directory
#include <sys/stat.h> 	

#include <math.h>	// fmod 
#include <fstream>	// MEAN AND STANDARD DEVIATION and  
                        // file I/O =  std::ofstream _experimentaldatafile;
#include <iomanip>      // std::setprecision
                        // format manipulation

#include<iostream>	// std::cout, std::endl
using namespace std; 

#include "boost/date_time/posix_time/posix_time.hpp" // -boost-get-current-time-in-milliseconds
using namespace boost::posix_time;

#include "armadillo" // C++ linear algebra library 
using namespace arma;


class Decimus
{

public:
        Decimus();
        virtual ~Decimus();


  /**
  * Print ACC,MAG and GYR data to the terminal
  */
  void printACCMAGGYR(float ACCX, float ACCY, float ACCZ, 
		      float MAGX, float MAGY, float MAGZ, 
		      float GYRX, float GYRY, float GYRZ);
  
  /**
  * Write ACC,MAG and GYR data to a csv file
  */
  void writeACCMAGGYR(float ACCX, float ACCY, float ACCZ, 
			  float MAGX, float MAGY, float MAGZ, 
			  float GYRX, float GYRY, float GYRZ);
  
  
  void writeYAWPITCHROLL(float YAW, float PITCH, float ROLL);

  
  
  /**
  * print the current time with _get_localdatetime
  */
  void testingzone();
 
  
  /**
   * Sensor Mode for Razor 9DOF 
   */
  enum Mode {
    YAW_PITCH_ROLL,
    ACC_MAG_GYR_RAW,
    ACC_MAG_GYR_CALIBRATED
    };

  /**
   * Time Delay Embedded Matrix using x as a vector input and
   * the embedded parameters "dim" and "tau".
   */
  mat TimeDelayEmbedding(rowvec x, int dim, int tau); 

  /**
   * Computing PCA using the embedded matrix
   */
  mat _EmbeddedMatrix_PCA(mat EmbeddedMatrix);

  /**
   * Setting embbedd parameters (dim, tau) and window lenght
   */
  void Set_SpaceReconstructionParameters(int lengthwindowframe, int dim, int tau);
     
  /**
   * Setting the Sensor Type
   */
  void SensorDataType (Mode mode);

  /**
   * Setting the sensor number
   */
  string sensor_number(string sensor_number);


  /**
   * Setting the user path name
   */
  string  userpathname(char * name);

private:

  Mode _dimode;

  mat _EmbeddedMatrix;
  mat _PCAScores;
  mat _push_back_PCAScores;

  rowvec _Eigenvalues;
  mat _push_back_Eigenvalues;  
  
  stringstream _PCANameFile;
  stringstream _EigenvaluesNameFile;

  //  void _mkdirNAME(std::string directoryName);
  void _mkdirNAME();

  
  /**
   * Add a new element at the end of the vector, after its current last element.
   * As similar as to vector::push_back method
   */
  void _push_back(float X, float Y, float Z); 
  mat _push_back_Matrix;
  
  /**
   * Obtain the magnitude of the given sensor
   */
  rowvec _magnitude( mat Matrix); 
  rowvec _magnitude_vector;
  
   /**
   * Obtain the modulo (remainder) of a given b
   */
    int mod (int a, int b);
  
  mat _mACC;
  
  int _length_window_frame;
  int _dim;// embedding dimension
  int _tau;// embedding time delay
  int _M; // embedding Matrix rows
  float _ACCX;
  float _ACCY;
  float _ACCZ;
  float _MAGX;
  float _MAGY;
  float _MAGZ; 
  float _GYRX; 
  float _GYRY;
  float _GYRZ;

  float _YAW;
  float _PITCH;
  float _ROLL;
  
  vector<long> _timelabel();
  unsigned int _dtsample;  // For saving the Discrete Sample Number
                             // (unsigned int: 0 to 4294967295)
 
  /**
   * File descriptor for csv file
   */  
  std::ofstream _experimentaldatafile;

  /**
  * defining the file descriptor and the localdatetime members
  */
  string _get_localdatetime(void);
 
  /**
   * Get the current directory to save the IMU log data
   */
  string _getCurrentDirectory();
  

  string _sensornumber;
  string _path_username;
  bool _dataanalysis_flag;
  
	
};

#endif // DECIMUS_H
