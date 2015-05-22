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

directory_name <- "test"
pattern_number <- ""
#star <- 50
#end <- 300
star <- 0
end <- 1000
window <- star:end;



#If you want to change your working directory to a subdirectory,
#then you can simply do this:

setwd("../")
#print ( getwd() )

setwd(paste(getwd(),"/data/",directory_name,"/",sep=""))  ; # set and get the current working directory
#print ( getwd() )
# setwd(paste(getwd(),"/",patternN,sep=""))  ; # set and get the current working directory

##list all files with a specific extension
files <-list.files(pattern = "\\.csv")


filename_imu0_1 <- files[1]
filename_imu0_2 <- files[2]
filename_imu0_3 <- files[3]
filename_imu0_4 <- files[4]





plot_timeseries_imus<- function(filename_imuN,window,patternN)
{
  
rawdata<-read.csv(paste(filename_imuN,"",sep=""), sep=',');
#If you want to move back up to the parent directory, the type

#wL <-length(window)
#N <- nrow(rawdata); #get the number of rows of the data file
#window <- 0:N;
#window <- 400:600;

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


# ############################################################
# #### Low-Pass Filter to remove the short-term fluctuations
# alpha <- 0.5
# data$eylp[1] <- 0
# data$erlp[1] <- 0
# for(i in 1:N) {
#    #print(data$ey[i])
#   #data$eylp[i+1] = data$ey[i]*alpha + ( (data$eylp[i])* (1-alpha)  )
#   data$erlp[i+1] = data$er[i]*alpha + ( (data$erlp[i])* (1-alpha)  )
# }
# ############################################################


###ACC
plotacc = xyplot( data$ax + data$ay + data$az + data$am ~ data$sample, data=rawdata, 
#xyplot( data$erlp ~ data$sample, data=rawdata, 
        #xyplot( data$accx ~ data$sample, data=rawdata, 
        pch=16, col.line = c('red', 'blue', 'green', 'black'), type = c("l","g"), lwd=3,
        main=list(label=paste(patternN, "_", substr(filename_imuN,1,4)," acc",sep=""), cex=2.5),
        xlab=list(label="Samples", cex=2),
        ylab=list(label="Raw Data", cex=2),

## LABELS
key=list(
  border= "grey", 
  text = list(c("X", "Y", "Z", "Mag")), 
  lines = list(pch=c(1,2,3,4), col= c('red','blue','green','black')), type="l", lwd=3,
  cex=2, # control the character expansion  of the symbols
  corner=c(0,0) # position
),
        
        grid = TRUE
)




###MAG
plotmag = xyplot( data$mx + data$my + data$mz + data$mm ~ data$sample, data=rawdata, 
        #xyplot( data$erlp ~ data$sample, data=rawdata, 
        #xyplot( data$accx ~ data$sample, data=rawdata, 
        pch=16, col.line = c('red', 'blue', 'green', 'black'), type = c("l","g"), lwd=3,
        main=list(label=paste(patternN, "_", substr(filename_imuN,1,4)," mag",sep=""), cex=2.5),
        xlab=list(label="Samples", cex=2),
        ylab=list(label="Raw Data", cex=2),
        
        ## LABELS
        key=list(
          border= "grey", 
          text = list(c("X", "Y", "Z", "Mag")), 
          lines = list(pch=c(1,2,3,4), col= c('red','blue','green','black')), type="l", lwd=3,
          cex=2, # control the character expansion  of the symbols
          corner=c(0,0) # position
        ),
        
        grid = TRUE
)


###GYRO
plotgyr = xyplot( data$gx + data$gy + data$gz + data$gm ~ data$sample, data=rawdata, 
        pch=16, col.line = c('red', 'blue', 'green', 'black'), type = c("l","g"), lwd=3,
        main=list(label=paste(patternN, "_", substr(filename_imuN,1,4)," gyro",sep=""), cex=2.5),
        xlab=list(label="Samples", cex=2),
        ylab=list(label="Raw Data", cex=2),
        
        ## LABELS
        key=list(
          border= "grey", 
          text = list(c("X", "Y", "Z", "Mag")), 
          lines = list(pch=c(1,2,3,4), col= c('red','blue','green','black')), type="l", lwd=3,
          cex=2, # control the character expansion  of the symbols
          corner=c(0,0) # position
        ),
        
        grid = TRUE
)

# 
# # print(pa, position=c(0,0.6,1,1), more=TRUE)
# # print(pm, position=c(0,0,1,.4))
print(plotacc)
print(plotmag)
print(plotgyr)
}
# 
# 
# dir.create("frame_windows")
# setwd(paste(getwd(),"/frame_windows",sep=""))  ; # set and get the current working directory
# 
# 
# dir.create(patternN)
# setwd(paste(getwd(),"/",patternN,sep=""))  ; # set and get the current working directory
# 
# 
# filename <- substr(filename_imuN,1,20)
# 
# write(data$ax, file = paste("ax_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# write(data$ay, file = paste("ay_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# write(data$az, file = paste("az_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# write(data$am, file = paste("am_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# 
# write(data$mx, file = paste("mx_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# write(data$my, file = paste("my_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# write(data$mz, file = paste("mz_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# write(data$mm, file = paste("mm_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# 
# write(data$gx, file = paste("gx_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# write(data$gy, file = paste("gy_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# write(data$gz, file = paste("gz_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# write(data$gm, file = paste("gm_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# 
# 
# 
# 
# setwd("../") #back to
# setwd("../") #back to
# 
# 
# }  
# 


plot_timeseries_imus(filename_imu0_1,window,pattern_number)
#plot_timeseries_imus(filename_imu0_2,window,pattern_number)


#back to R sourcecode path
setwd("../")
setwd("../")
setwd(paste(getwd(),"/R/",sep=""))  ; # set and get the current working directory

# write(data$ey, file = paste("yaw_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# write(data$ep, file = paste("pitch_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)
# write(data$er, file = paste("roll_wL",wL,"_",filename,".dat",sep=""), ncolumns=1)