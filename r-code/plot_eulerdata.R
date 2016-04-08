#
#  Displaying time-series data from Razor 9DOF IMU
#
# Miguel Perez-Xochicale
# Doctoral Researcher in Human-Robot Interaction
# University of Birmigham, U.K. (2014-2017)
#
# October 2015
#

library(lattice) ##xyplot
source(  paste(getwd(),"/functions.R",sep="") )

rawdata <- NULL;
data <- NULL;

directory_name <- "user"
pattern_number <- "pattern_#"
star <- 0
end <- 10000
windowlenght <- star:end;

setwd("../")
setwd(paste(getwd(),"/data/",directory_name,"/",sep="")); # set and get the current working directory
files <-list.files(pattern = "\\.csv")

lastfile <- length(files)

datafilename_imu0 <- files[ lastfile ]
#filename_imu0_ <- files[]



data <- getdata(datafilename_imu0)


plot_eulertimeseries<- function(data,patternN)
{
  
  plot_ypr = xyplot(  data[,3]+data[,4]+data[,5] ~ data[,1],
#  plot_ypr = xyplot(  data[,6]+data[,7]+data[,8] ~ data[,1],
      pch=16, col.line = c('red', 'blue', 'yellow3'), type = c("l","g"), lwd=6,
      main=list(label=paste(patternN, " ",sep=""), cex=2.5),
      xlab=list(label="Samples", cex=2),
      ylab=list(label="Raw Data", cex=2),
      scales = list(font=1, cex=2,
                    y=list(
                      at=seq(-180,180,30),limits=c(-200,200)
                          )
                  ),
                      
      ## LABELS
      key=list(
            border= "grey", 
            text = list(c("Yaw", "Pitch", "Roll")), 
            lines = list(pch=c(1,2,3), col= c('red','blue','yellow3')), type="l", lwd=4,
            cex=2, # control the character expansion  of the symbols
            corner=c(1,0) # position
                ),
            #function to modify the grid pattern
            panel=function(...) {
            panel.xyplot(...)
            panel.grid(h=-50, v=-1, col.line="blue", lwd=1, lty=3 )
            }
  )
  
print(plot_ypr)
  
}



plot_eulertimeseries(data,pattern_number)



#back to R sourcecode path
setwd("../")
setwd("../")
setwd(paste(getwd(),"/r-code/",sep=""))  ; # set and get the current working directory
