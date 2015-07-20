#
#  Displaying the time series data
#  from Razor 9DOF IMU
# 
#  Miguel Perez-Xochicale <perez.xochicale AT gmail.com>
#  University of Birmingham, UK
#  Wednesday, the 28th of January 2015
#

library(lattice) ##xyplot



rawdata <- NULL;
data <- NULL;

directory_name <- "human44"
pattern_number <- ""
star <- 0
end <- 10000
window <- star:end;


setwd("../")
setwd(paste(getwd(),"/data/",directory_name,"/",sep=""))  ; # set and get the current working directory
files <-list.files(pattern = "\\.csv")


filename_imu0_1 <- files[1]
filename_imu0_2 <- files[2]
filename_imu0_3 <- files[3]
filename_imu0_4 <- files[4]
filename_imu0_5 <- files[5]
filename_imu0_6 <- files[6]
filename_imu0_7 <- files[7]
filename_imu0_8 <- files[8]
filename_imu0_9 <- files[9]
#filename_imu0_ <- files[]


plot_timeseries_imus<- function(filename_imuN,window,patternN)
{
rawdata<-read.csv(paste(filename_imuN,"",sep=""), sep=',');

data$sample <- rawdata$Sample[window];
data$ax <- rawdata$ACCX[window];
data$ay <- rawdata$ACCY[window];
data$az <- rawdata$ACCZ[window];
data$am <- sqrt(data$ax^2 + data$ay^2 + data$az^2 );
data$mx <- rawdata$MAGX[window];
data$my <- rawdata$MAGY[window];
data$mz <- rawdata$MAGZ[window];
data$mm <- sqrt(data$mx^2 + data$my^2 + data$mz^2 );
data$gx <- rawdata$GYRX[window];
data$gy <- rawdata$GYRY[window];
data$gz <- rawdata$GYRZ[window];
data$gm <- sqrt(data$gx^2 + data$gy^2 + data$gz^2 );




###PLOT ACCELEROMETER DATA
plotacc = xyplot( data$ax + data$ay + data$az + data$am ~ data$sample, data=rawdata, 
#xyplot( data$erlp ~ data$sample, data=rawdata, 
        #xyplot( data$accx ~ data$sample, data=rawdata, 
        pch=16, col.line = c('red', 'blue', 'yellow3', 'black'), type = c("l","g"), lwd=3,
        main=list(label=paste(patternN, "_", substr(filename_imuN,1,4)," acc",sep=""), cex=2.5),
        xlab=list(label="Samples", cex=2),
        ylab=list(label="Raw Data", cex=2),
        scales = list(font=1, cex=2),

## LABELS
key=list(
  border= "grey", 
  text = list(c("X", "Y", "Z", "Mag")), 
  lines = list(pch=c(1,2,3,4), col= c('red','blue','yellow3','black')), type="l", lwd=3,
  cex=2, # control the character expansion  of the symbols
  corner=c(1,0) # position
),
        
        grid = TRUE
)




###PLOT MAGNETOMETER DATA
plotmag = xyplot( data$mx + data$my + data$mz + data$mm ~ data$sample, data=rawdata, 
        #xyplot( data$erlp ~ data$sample, data=rawdata, 
        #xyplot( data$accx ~ data$sample, data=rawdata, 
        pch=16, col.line = c('red', 'blue', 'yellow3', 'black'), type = c("l","g"), lwd=3,
        main=list(label=paste(patternN, "_", substr(filename_imuN,1,4)," mag",sep=""), cex=2.5),
        xlab=list(label="Samples", cex=2),
        ylab=list(label="Raw Data", cex=2),
        scales = list(font=1, cex=2),
        ## LABELS
        key=list(
          border= "grey", 
          text = list(c("X", "Y", "Z", "Mag")), 
          lines = list(pch=c(1,2,3,4), col= c('red','blue','yellow3','black')), type="l", lwd=3,
          cex=2, # control the character expansion  of the symbols
          corner=c(1,0) # position
        ),
        
        grid = TRUE
)


###PLOT GYROSCOPE DATA
plotgyr = xyplot( data$gx + data$gy + data$gz + data$gm ~ data$sample, data=rawdata, 
        pch=16, col.line = c('red', 'blue', 'yellow3', 'black'), type = c("l","g"), lwd=3,
        main=list(label=paste(patternN, "_", substr(filename_imuN,1,4)," gyro",sep=""), cex=2.5),
        xlab=list(label="Samples", cex=2),
        ylab=list(label="Raw Data", cex=2),
        scales = list(font=1, cex=2),
        
        ## LABELS
        key=list(
          border= "grey", 
          text = list(c("X", "Y", "Z", "Mag")), 
          lines = list(pch=c(1,2,3,4), col= c('red','blue','yellow3','black')), type="l", lwd=3,
          cex=2, # control the character expansion  of the symbols
          corner=c(1,0) # position
        ),
        
        grid = TRUE
)


print(plotacc)
print(plotmag)
print(plotgyr)
}


#plot_timeseries_imus(filename_imu0_[i],window,pattern_number)
plot_timeseries_imus(filename_imu0_3,window,pattern_number)


#back to R sourcecode path
setwd("../")
setwd("../")
setwd(paste(getwd(),"/R/",sep=""))  ; # set and get the current working directory

