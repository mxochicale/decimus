
#####################
# Functions 
# 
# Miguel Perez-Xochicale <perez.xochicale AT gmail.com>
# Doctoral Researcher in Human-Robot Interaction
# University of Birmigham, U.K. (2014-2017)

############
# How to use 
# add the following line to your main script 
# for the directory where the functions and the R scripts lives, you have to add
# source(  paste(getwd(),"/functions.R",sep="") )


####################
# Last Modication:
#
# 6th of October 
# Add rotated_angle function to rotate euler angles


#######
# TODO
# Create a main directory for the function file and mix all the functions for 
# the Human Variability Project
#
#
#


#################################
# getdata function
# gets data from a file and it's converted into a Matrix
# input:  filename
# output: Matrix Data (MD)
#         MD[,1] Sample
#         MD[,2] Time
#         MD[,3] Yaw
#         MD[,4] Pitch
#         MD[,5] Roll
#         MD[,6] rotated yaw
#         MD[,7] rotated pitch
#         MD[,8] rotated roll
#
getdata<- function(filename_imuN)
{
  threshold <- 1000
  
  rawdata<-read.csv(paste(filename_imuN,"",sep=""), sep=',');
  MD <- as.matrix(rawdata)# Matrix Data
  MD <- cbind (MD, rotated_angle(MD[,3],threshold)  )  #rotated yaw
  MD <- cbind (MD, rotated_angle(MD[,4],threshold)  )  #rotated pitch
  MD <- cbind (MD, rotated_angle(MD[,5],threshold)  )  #rotated roll
  
  return(MD)
  
}




rotated_angle <- function(eulerangle,threshold)
{
  new_ea_a <- 0;
  new_ea_b <- 0;
  new_ea <- 0;
  
  #calculate yaw offset
  avg_ea <- median(eulerangle)
  #define threshold based on movement range
  #thres = 200
  #find entries smaller than threshold
  aa <- which(eulerangle < (avg_ea - threshold))
  bb <- which(eulerangle > (avg_ea - threshold))
  
  #add 360 to move angles up
  new_ea_a[aa] <- eulerangle[aa] + 360
  new_ea_b[bb] <- eulerangle[bb] + 360
  
  #get offset for this signal
  avg_new_ea_a <- median(new_ea_a,na.rm = TRUE)
  avg_new_ea_b <- median(new_ea_b,na.rm = TRUE)
  #substract offset; boom   fluctuates around zero :-)
  final_ea_a = new_ea_a - avg_new_ea_a
  final_ea_b = new_ea_b - avg_new_ea_b
  
  new_ea[aa] <- final_ea_a[aa]
  new_ea[bb] <- final_ea_b[bb]
  
  return(new_ea)
}


