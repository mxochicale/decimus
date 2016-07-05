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


#include "Decimus.h"

Decimus::Decimus()
{
  _dtsample=0; // Initialize the discrete time sample
}

Decimus::~Decimus()
{
  Decimus::_experimentaldatafile.close();
}


string Decimus::_get_localdatetime ( void )
{
    time_t now = time(0);
    char the_date[18];
    the_date[0] = '\0';
    if (now != -1)
    {
      // strftime(the_date, 18, "-%d%m%Y-%H%M%S", gmtime(&now)); // Coordinated Universal Time
                                                                 // (UTC ) or its related successors
                                                                 // to Greenwich Mean Time
      strftime(the_date, sizeof(the_date), "%d%m%Y-%H%M%S", localtime(&now)); // local time
    }

    return std::string(the_date);
}

string Decimus::_getCurrentDirectory()
{
//   char resolved_path[199];
//   //realpath("../../", resolved_path);
//   realpath("../", resolved_path);
//   // cout << resolved_path << endl;
//   string path = resolved_path;


//   If resolved_path is specified as NULL, then realpath() uses malloc(3)
//   to allocate a buffer of up to PATH_MAX bytes to hold the resolved pathname,
//   and returns a pointer to this buffer. The caller should deallocate this
//   buffer using free(3).buffer using free(3).
  char *real_path = realpath("../../../", NULL);
  //cout << real_path << endl;
  string path = real_path;
  free(real_path);

  return path;
}

std::vector< long int > Decimus::_timelabel()
{
  ptime current_date_microseconds = microsec_clock::local_time();
  long millisecs = current_date_microseconds.time_of_day().total_milliseconds();
  time_duration current_time_milliseconds = milliseconds(millisecs);
  ptime current_date_milliseconds(current_date_microseconds.date(), current_time_milliseconds);

  //To convert hours minutes to seconds
  time_duration timeinseconds(current_time_milliseconds.hours(),
			      current_time_milliseconds.minutes(),
			      current_time_milliseconds.seconds(),0);
  // cout << "(h:m:s)time in seconds " << timeinseconds.total_seconds()  << endl;

  vector<long> msms;
    msms.push_back(timeinseconds.total_seconds());
    msms.push_back(current_time_milliseconds.fractional_seconds());

  return msms;
}


void Decimus::_mkdirNAME ()
{
  //  boost::filesystem::path dir(dir_path);
  //  boost::filesystem::path dir(Decimus::_getCurrentDirectory()+"/"+"ho/");
  //  boost::filesystem::create_directory(Decimus::_getCurrentDirectory()+"/"+"ho/");

  string directoryName = "data";
  string dN = (Decimus::_getCurrentDirectory()+"/"+directoryName +"/"); // directoryName
  int create_a_directory;
  create_a_directory = mkdir( ( (dN).c_str() ),  S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  string userpath = (dN + _path_username + "/");

  int create_a_user_directory;
  create_a_user_directory = mkdir( ( (userpath).c_str() ),  S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);


  Decimus::_experimentaldatafile.open( ( (userpath+_sensornumber+"_"+
					  Decimus::_get_localdatetime() +
					  ".csv").c_str()  ) , ios::out ); // create a csv file

//   // write the header tags to the csv file
//   if (_dimode == 0) {
//           Decimus::_experimentaldatafile << "Sample, Time, YAW, PITCH, ROLL" << endl;
//   }
//   else if (_dimode == 1) {
//       Decimus::_experimentaldatafile
// 	<< "Sample, Time, ACCX_RAW, ACCY_RAW, ACCZ_RAW, MAGX_RAW, MAGY_RAW, MAGZ_RAW, GYRX_RAW, GYRY_RAW, GYRZ_RAW" << endl;
//   }
//   else {
//       Decimus::_experimentaldatafile << "Sample, Time, ACCX, ACCY, ACCZ, MAGX, MAGY, MAGZ, GYRX, GYRY, GYRZ" << endl;
//   }

Decimus::_experimentaldatafile << "Sample, Time, ACCX, ACCY, ACCZ, MAGX, MAGY, MAGZ, GYRX, GYRY, GYRZ" << endl;

}



void Decimus::SensorDataType ( Decimus::Mode mode )
{
   _dimode = mode;
   //cout << "data input mode decimus " << _dimode << endl;
}




string Decimus::sensor_number(string sensor_number)
{
  _sensornumber = sensor_number;

    Decimus::_mkdirNAME ();


  return _sensornumber;
}


// char* Decimus::userpathname(char* name)
string Decimus::userpathname(char* name)
{
  string strname = name;
 _path_username = strname;
//   cout << "heyname" << _path_username << endl;
 return _path_username;
}





void Decimus::writeACCMAGGYR ( float ACCX, float ACCY, float ACCZ,
			       float MAGX, float MAGY, float MAGZ,
			       float GYRX, float GYRY, float GYRZ )
{
  _ACCX=ACCX;
  _ACCY=ACCY;
  _ACCZ=ACCZ;
  _MAGX=MAGX;
  _MAGY=MAGY;
  _MAGZ=MAGZ;
  _GYRX=GYRX;
  _GYRY=GYRY;
  _GYRZ=GYRZ;


  Decimus::_experimentaldatafile << fixed << setprecision(3)
  <<  _dtsample << ","  <<  _timelabel()[0] << "." << _timelabel()[1]
  << "," << _ACCX << "," << _ACCY << "," << _ACCZ
  << "," << _MAGX << "," << _MAGY << "," << _MAGZ
  << "," << _GYRX << "," << _GYRY << "," << _GYRZ //  repetition of the GYRY
  <<  std::endl;

  // Using 50 as the sample rate, we set the following modulus to
  // monitor data recording
  //  if ( Decimus::mod(_dtsample,50) == 49)
  //  {
  //    cout <<  (_dtsample+1)/50 << " s" << endl;
  //  }

   cout << "sample (n): " << _dtsample << endl;


  // FILE SAMPLE
  //
  // Sample, Time, ACCX, ACCY, ACCZ, MAGX, MAGY, MAGZ, GYRX, GYRY, GYRZ
  // 0,85439.939000,2.203,249.831,25.798,336.730,259.320,-5.656,-0.830,-1.620,-1.620
  // 1,85439.960000,2.203,250.713,25.798,338.624,260.319,-3.659,-0.830,-2.620,-2.620
  // 2,85439.979000,1.322,248.069,22.822,337.668,256.541,-0.763,-0.830,-3.620,-3.620

  _dtsample++;
}


void Decimus::writeYAWPITCHROLL(float YAW, float PITCH, float ROLL)
{
  _YAW=YAW;
  _PITCH=PITCH;
  _ROLL=ROLL;


  if (_dtsample == 0)
  {
    Decimus::_mkdirNAME ();
  }

  Decimus::_experimentaldatafile << fixed << setprecision(3)
  <<  _dtsample << ","  <<  _timelabel()[0] << "." << _timelabel()[1]
  << "," << _YAW << "," << _PITCH << "," << _ROLL
  <<  std::endl;

//   cout << _dtsample << endl;


   std::cout <<  _dtsample << "," <<  _timelabel()[0] << "." << _timelabel()[1] << ",  "
   << _YAW << "," << _PITCH << "," << _ROLL  <<  std::endl;

  // FILE SAMPLE
  //
  // Sample, Time, YAW, PITCH, ROLL
  // 0,39521.685000,-69.795,12.941,-3.762
  // 1,39521.685000,-70.867,12.526,-3.940
  // 2,39521.702000,-71.943,12.142,-4.067
  // 3,39521.742000,-72.969,11.758,-4.206

  _dtsample++;
}






void Decimus::printACCMAGGYR ( float ACCX, float ACCY, float ACCZ,
			       float MAGX, float MAGY, float MAGZ,
			       float GYRX, float GYRY, float GYRZ )
{
  _ACCX=ACCX;
  _ACCY=ACCY;
  _ACCZ=ACCZ;
  _MAGX=MAGX;
  _MAGY=MAGY;
  _MAGZ=MAGZ;
  _GYRX=GYRX;
  _GYRY=GYRY;
  _GYRZ=GYRZ;

 cout << "  sample " << _dtsample << fixed << setprecision(3)
 << "   ACC = " << setw(6) << _ACCX << ", " << setw(6) << _ACCY << ", " << setw(6) << _ACCZ
 << "   MAG = " << setw(7) << _MAGX << ", " << setw(7) << _MAGY << ", " << setw(7) << _MAGZ
 << "   GYR = " << setw(7) << _GYRX << ", " << setw(7) << _GYRY << ", " << setw(7) << _GYRZ << endl;

 _dtsample++; // increment the data sample value

}










void Decimus::_push_back ( float X, float Y, float Z )
{

  rowvec rowvector;

  if ( Decimus::mod(_dtsample,_length_window_frame) == 0) // equal to zero
  {
    _push_back_Matrix.clear(); //_mACC.zeros(m,3); // (rows,columns)
    rowvector << X << Y << Z;
    _push_back_Matrix.insert_rows(Decimus::mod(_dtsample,_length_window_frame), rowvector);
  }
 else // different from 0 and m-1
 {
    rowvector << X << Y << Z;
    _push_back_Matrix.insert_rows(Decimus::mod(_dtsample,_length_window_frame), rowvector);
 }

}
// void Decimus::_push_back_Matrix(float X, float Y, float Z, )


int Decimus::mod (int a, int b)
{
   if(b < 0) //you can check for b == 0 separately and do what you want
     return mod(-a, -b);
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}
//http://stackoverflow.com/questions/4003232/how-to-code-a-modulo-operator-in-c-c-obj-c-that-handles-negative-numbers




rowvec Decimus::_magnitude ( mat Matrix )
{

//   mat magMatrix;
//   magMatrix =  sqrt(sum(square(Matrix),1)); //sum( X, dim ) each column (dim=0), or each row (dim=1)
// //   cout <<"magMatrix"<< magMatrix << endl;
//   _magnitude_vector = trans(magMatrix);



// extract the pitch data as the magnitude vector
  mat PITCH = Matrix.col(1); // extract a column vector
  _magnitude_vector = trans(PITCH);



  return _magnitude_vector;
}



void Decimus::Set_SpaceReconstructionParameters (int lengthwindowframe, int dim, int tau )
{

    _dataanalysis_flag = true;
    _length_window_frame= lengthwindowframe;
    _dim = dim; // embedding dimension: m
    _tau = tau; // time delay: T

    _push_back_Matrix.zeros(_length_window_frame,3); // (rows,columns)
    _push_back_PCAScores.empty();
    _push_back_Eigenvalues.empty();

 // SAVE PCA and EIGENVALS in CVS files

    _PCANameFile << "Accumulated_PCA_Scores__FrameLenght=" << _length_window_frame
		 << "_dim=" << _dim << "_tau=" << _tau << ".csv";

    _EigenvaluesNameFile << "Accumulated_Eigenvalues__FrameLenght=" << _length_window_frame
			 << "_dim=" << _dim << "_tau=" << _tau << ".csv";

//     cout << "lenght" << _length_window_frame << "dim" << _dim << "T" << _tau << endl;
}






mat Decimus::TimeDelayEmbedding (rowvec x, int dim, int tau )
{
  int N, M;
  N=x.n_elem;
  M = N - (dim-1)*tau;

  _dim = dim;
  _tau = tau;
  _M = M;



  if (M<=0)
  {
    cout << "ERROR: EMBEDDING DIMENSION" << endl;
    cout << "       Using dim=" << dim << " and tau=" << tau << endl;
    cout << "       M value cannot be used for the embedded matrix:" << M << "x" << dim << endl;
    cout << "       M = N - (dim-1)*tau --> " << M << "=" << N << "-" <<  (dim-1)*tau << endl;
  }


  mat E(M,dim);
  E.zeros();

for (int i=0; i<M; i++){
for ( int k=0; k<dim; k++)
 {
//   cout << "pos" << i+(k*tau) << "val"<< x(i+(k*tau)) << endl;
  E(i,k)=x(i+(k*tau));
 }}

//    cout << "***Standard Embedded Matrix  (dim=" << _dim << ", tau="<< _tau << ")  ... " << "[" << _M << "x" << _dim << "] \n" << endl;

  _EmbeddedMatrix = E;

  return _EmbeddedMatrix;
}






mat Decimus::_EmbeddedMatrix_PCA ( mat EmbeddedMatrix )
{

    mat center_vector_mean = mean(EmbeddedMatrix, 0 ); // column matrix called mean
    cout << "column mean" << center_vector_mean << endl;

      for (int k=0; k<_M; k++)
  {
//     cout<< EmbeddedMatrix.col(0) - mean_EM << endl;
    EmbeddedMatrix.row(k) = EmbeddedMatrix.row(k) - center_vector_mean;
  }
   cout << "center EmbeddedMatrix = EmbeddedMatrix.row(k) - center_vector_mean \n"
   << EmbeddedMatrix << endl;


/////////////////////////////////////
/////////////////////////////////////
// Do It Yourself Method to compute the Principal Component Analysis
  mat A;

     A= EmbeddedMatrix.t() * EmbeddedMatrix; // generate a symmetric matrix --- mat B = A.t()*A;
//   cout << "A = X*X \n" << A << endl;

vec eigval_original, eigval;
mat eigvec_original, eigvec, transformedData;
 eig_sym(eigval_original, eigvec_original, A.t(), "dc");
// eig_sym( eigval, eigvec, X, method )
// Eigen decomposition of dense symmetric/hermitian matrix X
//The method argument is optional; method is either "dc" or "std", with "dc" indicating divide-and-conquer
// and "std" indicating standard
//     In version 4.000 and later, the default method is "dc"
//     In version 3.930, the default method is "std"

// fliplr(): generate a copy of matrix X, with the order of the columns reversed
// flipud(): generate a copy of matrix X, with the order of the rows reversed

 eigval = flipud(eigval_original);
 eigvec = fliplr(eigvec_original);
 transformedData = fliplr(eigvec_original).t()*EmbeddedMatrix.t();

  cout << "DIY:eigenvalues \n" << eigval << endl;
  cout << "DIY:eigenvectors \n" << eigvec << endl;
  cout << "DIY:transformedData \n" << transformedData << endl;




//   ///// Singular Value Decomposition
//   mat U;
//   vec s;
//   mat V;
//
//   svd(U,s,V,EmbeddedMatrix);
//
//   cout << "DIY:svd U \n" << U << endl;
//   cout << "DIY:svd s \n" << s << endl;
//   cout << "DIY:svd V:eigenvectors \n" << V << endl;
//


//   //////////////MLpack
//   mat  coeff1;
//   vec eigVal1;
//   mat  score1;
//
//
//   PCA p;
//   p.Apply(EmbeddedMatrix.t() , score1, eigVal1, coeff1);
//   //   PCA::Apply(data,transformedData,eigval,eigvec)
// //   Parameters:
// //   	data 	Data matrix.
// // 	transformedData 	Matrix to put results of PCA into.
// // 	eigval 	Vector to put eigenvalues into.
// // 	eigvec 	Matrix to put eigenvectors (loadings) into.
// //   *It is safe to pass the same matrix reference for both data and transformedData.
// //
//
// cout << "mlpack:PCA::eigenvalues of cov(X)\n" << eigVal1 << endl;
// cout << "mlpack:PCA::einvec\n" << coeff1 << endl;
// cout << "mlpack:PCA::transformedData\n" << score1 << endl;


/////////////////////////////////////
/////////////////////////////////////




//   mat coeff;
//   vec eigVal;
//   mat score;
//
// ////////////////////////////////////////
// //ARMADILLO Principal Component Analysis
// //http://arma.sourceforge.net/docs.html#princomp
// //   princomp(coeff, score, eigVal, trans(EmbeddedMatrix));
//
//   princomp(coeff, score, eigVal, EmbeddedMatrix);

//     //   output objects:
//     //
//     //     coeff: principal component coefficients
//     //     score: projected data
//     //     latent: eigenvalues of the covariance matrix of X
//     //     tsquared: Hotteling's statistic for each sample
// cout << "armadillo:PCA:eigenvalues of cov(X)\n" << eigVal << endl; // print the matrix data
// cout << "armadillo:PCA:Rotation Matrix\n" << coeff << endl; // print the matrix data
// cout << "armadillo:PCA:transformedData\n" << score << endl; // print the matrix data
// _Eigenvalues = trans(eigVal);
// _PCAScores = score;
// return _PCAScores;; //  return PCAScore or R_PCA$x


_Eigenvalues = trans(eigval); //trans() is used to solve the following error
// 				error: Mat::init(): requested size is not compatible with row vector layout

_PCAScores = transformedData;
return _PCAScores;; //  return PCAScore or R_PCA$x


}






void Decimus::testingzone()
{
  /**
   * Comment/Uncomment the following section for testing printable methods
   *
   *
   */
//   cout << endl;
//   cout << "  ***********************************     "  << endl;
//   cout << "    Local Date and Time: " << Decimus::_get_localdatetime() << endl;
//   cout << "    Get Current Directory " <<  Decimus::_getCurrentDirectory() << endl;

//   cout << "\n \n \n" ;
//   cout << "  " << "***********************************     "  << endl;

     // // When using _mkdirNAME twice does not create the file to save data
//   Decimus::_mkdirNAME ("data");
}
