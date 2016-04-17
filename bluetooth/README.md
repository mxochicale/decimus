

Configure rfcomm as regular user
============================
```
sudo chmod u+s /usr/bin/rfcomm
```

Pairing Bluetooth Dongle
============================
It is recommended that you install blueman for pairing the bluetooh modules
using bluetooth devices application

```
sudo apt-get update
sudo apt-get install blueman
```

Example Usage
--
* Scan the nearby bluetooth connections

```
$ hcitool scan
Scanning ...
00:18:B2:03:77:7B	Serial Port Device
```

* When a device has been discovered, l2ping is used to test the connection

```
$ sudo l2ping 00:18:B2:03:77:7B -c 2
Ping: 00:18:B2:03:77:7B from AC:xx:xx:xx:xx:xx (data size 44) ...
44 bytes from 00:18:B2:03:77:7B id 0 time 8.85ms
44 bytes from 00:18:B2:03:77:7B id 1 time 5.90ms
2 sent, 2 received, 0% loss
```

* Connect the device to rfcomm 0
```
$ sudo rfcomm connect 0 00:18:B2:03:77:7B
Connected /dev/rfcomm0 to 00:18:B2:03:77:7B on channel 1
Press CTRL-C for hangup
```

* Release the port
```
$ sudo rfcomm release 0  00:18:B2:03:77:7B
```


* Prior to run the application, it is recommended that you test the IMU sensor by using
```
$ sudo miniterm.py /dev/rfcomm0 -b 57600
--- Miniterm on /dev/rfcomm0: 57600,8,N,1 ---
--- Quit: Ctrl+]  |  Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
```

      // Streaming output
      "#o0" - DISABLE continuous streaming output. Also see #f below.
      "#o1" - ENABLE continuous streaming output.


N bluetooth devices
============================

In order to connect to N bluetooth devices automatically,
it would be easier to add the mac addresses of the bluetooth modules in rfcomm.conf file.
To do this, you have to either create or open the "/etc/bluetooth/rfcomm.conf"

```
$sudo vim /etc/bluetooth/rfcomm.conf
```
and add the following lines
```
rfcomm0 {
        bind no;
        device 00:18:B2:03:77:7B;
        channel 1;
        comment "Serial Port";
        }
```
Then, simply run to
```
$sudo rfcomm connect 0
Connected /dev/rfcomm0 to 00:18:B2:03:77:7B on channel 1
Press CTRL-C for hangup

```

You can also simply modify https://github.com/mxochicale/decimus/blob/master/bluetooth/rfcomm.conf

Connecting  Bluetooth Adaptors (dongles)
============================

BLUENEXT micro bluetooth2.0 USB adaptor
--

```
$ dmesg|tail
[24864.443789] usb 9-2: new full-speed USB device number 5 using uhci_hcd
[24865.126300] usb 9-2: New USB device found, idVendor=0a12, idProduct=0001
[24865.126306] usb 9-2: New USB device strings: Mfr=0, Product=2, SerialNumber=0
[24865.126310] usb 9-2: Product: BT2.0
```

```
$ lsusb
Bus 009 Device 004: ID 0a12:0001 Cambridge Silicon Radio, Ltd Bluetooth Dongle (HCI mode)
```


```
$ hcitool dev
Devices:
	hci0	00:1A:7D:DA:71:13
```

Bluetooth 4.0 dongle CSR8510
--

```
$ dmesg|tail
[27653.847335] usb 9-1: new full-speed USB device number 7 using uhci_hcd
[27654.013502] usb 9-1: New USB device found, idVendor=0a12, idProduct=0001
[27654.013508] usb 9-1: New USB device strings: Mfr=0, Product=2, SerialNumber=0
[27654.013511] usb 9-1: Product: CSR8510 A10
```

```
$ lsusb
Bus 009 Device 007: ID 0a12:0001 Cambridge Silicon Radio, Ltd Bluetooth Dongle (HCI mode)
```

Two Bluetooth Adaptors
--

```
$ lsusb
Bus 009 Device 008: ID 0a12:0001 Cambridge Silicon Radio, Ltd Bluetooth Dongle (HCI mode)
Bus 009 Device 007: ID 0a12:0001 Cambridge Silicon Radio, Ltd Bluetooth Dongle (HCI mode)
```

```
$ hcitool dev
Devices:
	hci1	00:30:91:10:00:26
	hci0	00:1A:7D:DA:71:13
```



Connecting four ARF7044 bluetooth modules to two different bluetooth dongles (bluenext and CSR 4.0)
--

```
$ hcitool scan
Scanning ...
	00:19:0E:08:0A:3F	eee294.bham.ac.uk-0
	00:18:B2:03:77:7C	Serial Port Device
	00:18:B2:03:77:7D	Serial Port Device
	00:18:B2:03:77:7B	Serial Port Device
	00:18:B2:02:EA:18	Serial Port Device
```

```
$ hcitool dev
Devices:
	hci1	00:30:91:10:00:26
	hci0	00:1A:7D:DA:71:13
```



```
$ rfcomm -i hci0 connect 0
Connected /dev/rfcomm0 to 00:18:B2:03:77:7B on channel 1
Press CTRL-C for hangup
```

```
$ rfcomm -i hci0 connect 1
Connected /dev/rfcomm1 to 00:18:B2:03:77:7C on channel 1
Press CTRL-C for hangup
```

```
$ rfcomm -i hci1 connect 2
Connected /dev/rfcomm2 to 00:18:B2:03:77:7D on channel 1
Press CTRL-C for hangup
```

```
$ rfcomm -i hci1 connect 3
Connected /dev/rfcomm3 to 00:18:B2:02:EA:18 on channel 1
Press CTRL-C for hangup
```


Useful commands
--


* To restart the bluetooth daemon:

```
$ sudo /etc/init.d/bluetooth restart
 * Stopping bluetooth                                                                          [ OK ]
 * Starting bluetooth                                                                          [ OK ]
```


Setting up the BlueSMiRF's baudrate
======================================

```
$ hcitool scan
Scanning ...
	00:06:66:71:5B:C8	RNBT-5BC8
```

Changing BAUD rat on BlueSMiRF modules
--

connect the FTDI to one of the USB ports
```
$ ll /dev/serial/by-id/
480964 lrwxrwxrwx 1 root root 13 Dec 15 14:01 usb-FTDI_FT232R_USB_UART_A100RVV0-if00-port0 -> ../../ttyUSB0
```

To change default baud rate, follow these instructions
A good tutorial to change the  BAUD rate on BlueSMiRF Gold is available at https://www.youtube.com/watch?v=Qa-G0FvI98U
$ sudo miniterm.py /dev/ttyUSB0 -b 115200

```
$$$$
CMD

$su,57
AOK
?

$d
***Settings***
BTA=000666715BC8
BTName=RNBT-5BC8
Baudrt=57.6
Mode  =Slav
Authen=0
PinCod=1234
Bonded=0
Rem=000666715BC3
?

$---
END
```

once the bluetooth dongle has been configurated, you need to change the baudrate to establish any connection

```
$ sudo miniterm.py /dev/ttyUSB0 -b 57600
```



Multiple Terminals
=====================

Expect is useful for running any program which requires interaction between the program and the user.
In Ubuntu multixterm included in expect package. Install expect in Ubuntu:

```
$sudo apt-get install expect
```



References
===========
https://myraspberryandme.wordpress.com/2013/11/20/bluetooth-serial-communication-with-hc-05/


http://www.armadeus.com/wiki/index.php?title=Bluetooth
for [$ rfcomm -i hci0 listen /dev/rfcomm0 7 &]
