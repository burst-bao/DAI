Overview
========

The enet_rxtx_rxinterrupt example shows the simplest way to use ENET transactional tx/rx API for simple frame receive and transmit.

1. This example shows how to initialize the ENET.
2. How to use ENET to receive frame in polling and to transmit frame.

The example transmits 20 number broadcast frame, print the number and the mac address of 
the recieved frames.

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


Transmission start now!
The 1 frame transmitted success!
The 2 frame transmitted success!
The 3 frame transmitted success!
The 4 frame transmitted success!
The 5 frame transmitted success!
The 6 frame transmitted success!
The 7 frame transmitted success!
The 8 frame transmitted success!
The 9 frame transmitted success!
The 10 frame transmitted success!
The 11 frame transmitted success!
The 12 frame transmitted success!
The 13 frame transmitted success!
The 14 frame transmitted success!
The 15 frame transmitted success!
The 16 frame transmitted success!
The 17 frame transmitted success!
The 18 frame transmitted success!
The 19 frame transmitted success!
The 20 frame transmitted success!
 One frame received. the length 346
 Dest Address ff:ff:ff:ff:ff:ff Src Address 28:f1: e:12:1f:10
 One frame received. the length 64
 Dest Address ff:ff:ff:ff:ff:ff Src Address 28:f1: e:12:1f:10
 One frame received. the length 64
 Dest Address ff:ff:ff:ff:ff:ff Src Address 28:f1: e:12:1f:1

...

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Customization options
=====================

