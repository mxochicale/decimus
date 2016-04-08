#
#  Displaying the time series data
#  from Razor 9DOF IMU
# 
#  Miguel Perez-Xochicale <perez.xochicale AT gmail.com>
#  University of Birmingham, UK
#  Wednesday, the 28th of January 2015
#

library(lattice) ##xyplot
source(  paste(getwd(),"/functions.R",sep="") )

rawdata <- NULL;
data <- NULL;

directory_name <- "user"

pattern_number <- ""
star <- 0
end <- 10000
window <- star:end;


setwd("../")
setwd(paste(getwd(),"/data/",directory_name,"/",sep="")); # set and get the current working directory
files <-list.files(pattern = "\\.csv")

lastfile <- length(files)

datafilename_imu0 <- files[ lastfile ]

data <- get_ACCMAGGYRdata(datafilename_imu0)


#back to R sourcecode path
setwd("../")
setwd("../")
setwd(paste(getwd(),"/r-code/",sep=""))  ; # set and get the current working directory



############################################################
############################################################


plot_acc<- function(data,patternN)
{ 
  ###PLOT ACCELEROMETER DATA
  plot_acc = xyplot(  data[,3]+data[,4]+data[,5] ~ data[,1],
                      #  plot_ypr = xyplot(  data[,6]+data[,7]+data[,8] ~ data[,1],
                      pch=16, col.line = c('red', 'blue', 'yellow3'), type = c("l","g"), lwd=6,
                      main=list(label=paste(patternN, " ",sep=""), cex=2.5),
                      xlab=list(label="Samples", cex=3, fontfamily="Times"),
                      ylab=list(label="Raw Data", cex=3, fontfamily="Times"),
                      scales = list(font=1, cex=2,
                                    y=list(
                                      at=seq(-500,500,100),limits=c(-550,550)
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
#print(plot_mag)
#print(plot_gyr)
}

png(file = "plotacc.png", width = 1500, height = 900, units = "px", bg = "white")
plot_acc(data,pattern_number)
dev.off()


plot_mag<- function(data,patternN)
{ 

  
  ###PLOT MAGNETOMETER DATA
  plot_mag = xyplot(  data[,6]+data[,7]+data[,8] ~ data[,1],
                      #  plot_ypr = xyplot(  data[,6]+data[,7]+data[,8] ~ data[,1],
                      pch=16, col.line = c('red', 'blue', 'yellow3'), type = c("l","g"), lwd=6,
                      main=list(label=paste(patternN, " ",sep=""), cex=2.5),
                      xlab=list(label="Samples", cex=3, fontfamily="Times"),
                      ylab=list(label="Raw Data", cex=3, fontfamily="Times"),
                      scales = list(font=1, cex=2,
                                    y=list(
                                      at=seq(-800,800,100),limits=c(-800,800)
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

png(file = "plotmag.png", width = 1500, height = 900, units = "px", bg = "white")
plot_mag(data,pattern_number)
dev.off()



plot_gyr<- function(data,patternN)
{ 

  ###PLOT GYROSCOPE DATA
  plot_gyr = xyplot(  data[,9]+data[,10]+data[,11] ~ data[,1],
                      #  plot_ypr = xyplot(  data[,6]+data[,7]+data[,8] ~ data[,1],
                      pch=16, col.line = c('red', 'blue', 'yellow3'), type = c("l","g"), lwd=6,
                      main=list(label=paste(patternN, " ",sep=""), cex=2.5),
                      xlab=list(label="Samples", cex=3, fontfamily="Times"),
                      ylab=list(label="Raw Data", cex=3, fontfamily="Times"),
                      scales = list(font=1, cex=2,
                                    y=list(
                                      at=seq(-10000,10000,1000),limits=c(-10000,10000)
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

png(file = "plotgyr.png", width = 1500, height = 900, units = "px", bg = "white")
plot_gyr(data,pattern_number)
dev.off()





# 
# 
# plot_timeseries_imus<- function(filename_imuN,window,patternN)
# {
# 
# ###PLOT ACCELEROMETER DATA
# plotacc = xyplot( data$ax + data$ay + data$az + data$am ~ data$sample, data=rawdata, 
# #xyplot( data$erlp ~ data$sample, data=rawdata, 
#         #xyplot( data$accx ~ data$sample, data=rawdata, 
#         pch=16, col.line = c('red', 'blue', 'yellow3', 'black'), type = c("l","g"), lwd=3,
#         main=list(label=paste(patternN, "_", substr(filename_imuN,1,4)," acc",sep=""), cex=2.5),
#         xlab=list(label="Samples", cex=2),
#         ylab=list(label="Raw Data", cex=2),
#         scales = list(font=1, cex=2),
# 
# ## LABELS
# key=list(
#   border= "grey", 
#   text = list(c("X", "Y", "Z", "Mag")), 
#   lines = list(pch=c(1,2,3,4), col= c('red','blue','yellow3','black')), type="l", lwd=3,
#   cex=2, # control the character expansion  of the symbols
#   corner=c(1,0) # position
# ),
#         
#         grid = TRUE
# )
# 
# #plot_timeseries_imus(filename_imu0_[i],window,pattern_number)
# plot_timeseries_imus(filename_imu0_0,window,pattern_number)






