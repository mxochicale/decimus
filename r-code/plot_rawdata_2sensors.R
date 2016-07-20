#------------------------------------------------------------
#  Displaying the time series data from 2 Razor 9DOF IMU
#
#                        miguel [http://mXOCHICALE.github.io]
#              Doctoral Researcher in Human-Robot Interaction
#                @ University of Birmingham, U.K. (2014-2018)
#------------------------------------------------------------

if (!require("lattice")) install.packages("lattice")
library(lattice)


#############################################
# Setting r-script and function paths
#
setwd("../")
main_path <- getwd()
r_code_path <- paste(main_path,"/r-code/",sep="")

source(paste(main_path,"/r-code/functions.R",sep="") ) # Load functions


#############################################
# Reading csv files
#
data_path_name <- "nao2"
setwd(paste(main_path,"/data/",data_path_name,"/",sep=""));

details = file.info(list.files(pattern="*.csv"))
details = details[with(details, order(as.POSIXct(atime))), ]
files = rownames(details)



################################
## Using the most recent files

TAGIMU <- "imu1"
#TAGIMU <- "imu3"


extract_imu_num <- substring ( files[ length(files)  ], 1,4)

if ( extract_imu_num == TAGIMU ){
imuB <- get_ACCMAGGYRdata( files[ length(files)    ] )
imuA <- get_ACCMAGGYRdata( files[ length(files)-1    ] )
} else{
imuB <- get_ACCMAGGYRdata( files[ length(files)-1    ] )
imuA <- get_ACCMAGGYRdata( files[ length(files)    ] )
}





#############################################
# Create a path to save the graphical results
#
setwd(r_code_path)
plots_path <- "plots_2imus"
if (file.exists(plots_path)){
  setwd(file.path(r_code_path, plots_path))
} else {
  dir.create(plots_path)
  setwd(file.path(r_code_path, plots_path))
}

maxlength_imuA <- dim(imuA)[1]
maxlength_imuB <- dim(imuB)[1]
window_imuA <- 00:maxlength_imuA
window_imuB <- 00:maxlength_imuB


#############################################
# Plotting and saving the png files curves
#
png(file = "plotACC_imuA.png", width = 1000, height = 700, units = "px", bg = "white")
plot_acc(imuA, window_imuA)
dev.off()

png(file = "plotACC_imuB.png", width = 1000, height = 700, units = "px", bg = "white")
plot_acc(imuB, window_imuB)
dev.off()

png(file = "plotMAG_imuA.png", width = 1000, height = 700, units = "px", bg = "white")
plot_mag(imuA, window_imuA)
dev.off()

png(file = "ploMAG_imuB.png", width = 1000, height = 700, units = "px", bg = "white")
plot_mag(imuB, window_imuB)
dev.off()

png(file = "plotGYR_imuA.png", width = 1000, height = 700, units = "px", bg = "white")
plot_gyr(imuA, window_imuA)
dev.off()

png(file = "ploGYR_imuB.png", width = 1000, height = 700, units = "px", bg = "white")
plot_gyr(imuB, window_imuB)
dev.off()


TwoSensorAxis <- 4
TwoSensorWindowFrame <- 000:1000
png(file = "plot_2imus_same_axis.png", width = 1000, height = 700, units = "px", bg = "white")
plot_2razor_imus(imuA, imuB, TwoSensorAxis, TwoSensorWindowFrame)
dev.off()





setwd(r_code_path) ## go back to the r-script source path
