!/bin/bash
#
#  chmod +x <filename>.sh
#  Thu Jun 11 15:03:42 BST 2015
#
#                        miguel [http://mxochicale.github.io]
#              Doctoral Researcher in Human-Robot Interaction
#                @ University of Birmingham, U.K. (2014-2018)
#------------------------------------------------------------




echo "-------------------------------"
echo "release and connect"
echo "-------------------------------"


#Restart the BT services:
/etc/init.d/bluetooth stop
/etc/init.d/bluetooth start
#rfcomm release 0 & rfcomm release 1
#sleep 1
rfcomm connect 0 & rfcomm connect 1


echo "-------------------------------"
echo "rfcomm released"
echo "-------------------------------"
