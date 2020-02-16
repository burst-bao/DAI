Overview
========

The enet_rxtx_ptp1588_transfer example shows the way to use ENET driver to  
 receive and transmit frame in the 1588 feature required cases.

1. This example shows how to initialize the ENET.
2. How to get the time stamp of the PTP 1588 timer.
3. How to use Get the ENET transmit and receive frame time stamp.

The example transmits 20 number PTP event frame, shows the timestamp of the transmitted frame.
The length, source MAC address and destination MAC address of the received frame will be print. 
The time stamp of the received timestamp will be print when the PTP message frame is received(the outside loopback cable can be used to see the right rx time-stamping log since we send the ptp message). 

Toolchain supported
===================
- IAR embedded Workbench  8.40.2
- Keil MDK  5.29
- MCUXpresso  11.1.0
- GCC ARM Embedded  8.3.1

Hardware requirements
=====================
- Mini/micro USB cable
- LPCXpresso54608 board
- Personal Computer
- RJ45 Network cable

Board settings
==============
For LPCXpresso54608 V2.0:JP11 and JP12 1-2 on. 

Prepare the Demo
================
1.  Connect a USB cable between the host PC and the OpenSDA USB port on the target board.
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Insert the Ethernet Cable into the target board's RJ45 port and connect it to a router (or other DHCP server capable device).
4.  Download the program to the target board.
5.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
The log below shows example output of the example in the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ENET example start.
 Get the 1-th time xx second xx nanosecond
 Get the 2-th time xx second xx nanosecond
 Get the 3-th time xx second xx nanosecond
 ......

 Get the 10-th time xx second xx nanosecond


Transmission start now!
The 1 frame transmitted success!
 the timestamp is xx second xx nanosecond
The 2 frame transmitted success! 
 the timestamp is xx second, xx nanosecond
 
Note: the xx second and xx nanosecond should be the number with solid increment.

the transmitted frame is a 1000 length broadcast frame. the frame can be seen
when the PC is installed with wireshark.

when a 1000 length normal messsage frame is received, the log would be added like:
A frame received. the length xxx 
when a 1000 length ptp event message frame is received, the log would be added to the terminal like:
A frame received. the length xxx 
  the timestamp is xx second, xx nanosecond

...

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Customization options
=====================

