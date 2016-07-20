#------------------------------------------------------------
#  Functions
#
#                        miguel [http://mXOCHICALE.github.io]
#              Doctoral Researcher in Human-Robot Interaction
#                @ University of Birmingham, U.K. (2014-2018)
#------------------------------------------------------------

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


get_ACCMAGGYRdata<- function(filename_imuN)
{

  rawdata<-read.csv( paste(filename_imuN,"",sep=""), sep=',', header=FALSE);
  MD <- as.matrix(rawdata)# Matrix Data

  #MD <- cbind (MD, sqrt(MD[,3]^2 + MD[,4]^2 + MD[,5]^2) ); # magnitude of ACC
  #MD <- cbind (MD, sqrt(MD[,6]^2 + MD[,7]^2 + MD[,8]^2) ); # magnitude of MAG
  #MD <- cbind (MD, sqrt(MD[,9]^2 + MD[,10]^2 + MD[,11]^2) ); # magnitude of GYR

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


##############################
###PLOT ACCELEROMETER DATA
plot_acc<- function(data,window)
{
  plot_acc <- xyplot( data[window,2]+data[window,3]+data[window,4] ~ data[window,1],
                      pch=16, col.line = c('red', 'blue', 'yellow3'), type = c("l","g"), lwd=6,
                      main=list(label=paste(" ",sep=""), cex=2.5),
                      xlab=list(label="Samples", cex=3, fontfamily="Times"),
                      ylab=list(label="Raw Data", cex=3, fontfamily="Times"),
                      scales = list(font=1, cex=2,
                                    y=list(
                                      at=seq(-600,600,100),limits=c(-650,650)
                                    )
                      ),

                      ## LABELS
                      key=list(
                        border= "grey",
                        text = list(c(expression(A[x]), expression(A[y]), expression(A[z]))),
                        lines = list(pch=c(1,2,3), col= c('red','blue','yellow3')), type="l", lwd=5,
                        cex=2.25, # control the character expansion  of the symbols
                        corner=c(1,0) # position
                      ),
                      #function to modify the grid pattern
                      panel=function(...) {
                        panel.xyplot(...)
                        panel.grid(h=-50, v=-1, col.line="blue", lwd=1, lty=3 )
                      }
                      )

print(plot_acc)
}


##############################
###PLOT MAGNETOMETER DATA
plot_mag<- function(data,window)
{
 plot_mag <- xyplot(  data[window,5]+data[window,6]+data[window,7] ~ data[window,1],
                      pch=16, col.line = c('red', 'blue', 'yellow3'), type = c("l","g"), lwd=6,
                      main=list(label=paste(" ",sep=""), cex=2.5),
                      xlab=list(label="Samples", cex=3, fontfamily="Times"),
                      ylab=list(label="Raw Data", cex=3, fontfamily="Times"),
                      scales = list(font=1, cex=2,
                                    y=list(
                                      at=seq(-1000,1000,200),limits=c(-1000,1000)
                                    )
                      ),

                      ## LABELS
                      key=list(
                        border= "grey",
                        text = list(c(expression(M[x]), expression(M[y]), expression(M[z]))),
                        lines = list(pch=c(1,2,3), col= c('red','blue','yellow3')), type="l", lwd=5,
                        cex=2.25, # control the character expansion  of the symbols
                        corner=c(1,0) # position
                      ),
                      #function to modify the grid pattern
                      panel=function(...) {
                        panel.xyplot(...)
                        panel.grid(h=-50, v=-1, col.line="blue", lwd=1, lty=3 )
                      }
                      )
print(plot_mag)
}


##############################
###PLOT GYROSCOPE DATA
plot_gyr<- function(data,window)
{
  plot_gyr <- xyplot(  data[window,8]+data[window,9]+data[window,10] ~ data[window,1],
                      pch=16, col.line = c('red', 'blue', 'yellow3'), type = c("l","g"), lwd=6,
                      main=list(label=paste(" ",sep=""), cex=2.5),
                      xlab=list(label="Samples", cex=3, fontfamily="Times"),
                      ylab=list(label="Raw Data", cex=3, fontfamily="Times"),
                      scales = list(font=1, cex=2,
                                    y=list(
                                    at=seq(-25000,25000,5000),limits=c(-25000,25000)
                                    )
                      ),

                      ## LABELS
                      key=list(
                        border= "grey",
                        text = list(c(expression(G[x]), expression(G[y]), expression(G[z]))),
                        lines = list(pch=c(1,2,3), col= c('red','blue','yellow3')), type="l", lwd=5,
                        cex=2.25, # control the character expansion  of the symbols
                        corner=c(1,0) # position
                      ),
                      #function to modify the grid pattern
                      panel=function(...) {
                        panel.xyplot(...)
                        panel.grid(h=-50, v=-1, col.line="blue", lwd=1, lty=3 )
                      }
  )

print(plot_gyr)
}





##############################
###PLOT GYROSCOPE DATA
plot_2razor_imus<- function(data_razor_imu0,data_razor_imu1,axis_number, window)
{


plot <- xyplot(  data_razor_imu0[window,axis_number] + data_razor_imu1[window,axis_number] ~ window,
        pch=16, col.line = c('red', 'blue', 'black'),
        type = c("l","g"), lwd=5,
        main=list(label=paste(" ",sep=""), cex=2.5),
        xlab=list(label="Samples", cex=3, fontfamily="Times"),
        ylab=list(label="Raw Data", cex=3, fontfamily="Times")
        )

print(plot)

}
