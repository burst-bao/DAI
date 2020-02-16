Overview
========

The enet_rxtx_rxinterrupt example shows the simplest way to use ENET functional tx/rx API for simple frame receive and transmit.

1. This example shows how to initialize the ENET.
2. How to use ENET to receive frame in interrupt irq handler and to transmit frame.

The example transmits 20 number broadcast frame, print the number of recieved frames. To avoid
the receive number overflow, the transmit/receive loop with automatically break when 20 number
are received.



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
The 1-th frame transmitted success!
The 2-th frame transmitted success!
The 3-th frame transmitted success!
The 4-th frame transmitted success!
The 5-th frame transmitted success!
The 6-th frame transmitted success!
The 7-th frame transmitted success!
The 8-th frame transmitted success!
The 9-th frame transmitted success!
The 10-th frame transmitted success!
The 11-th frame transmitted success!
The 12-th frame transmitted success!
The 13-th frame transmitted success!
The 14-th frame transmitted success!
The 15-th frame transmitted success!
The 16-th frame transmitted success!
The 17-th frame transmitted success!
The 18-th frame transmitted success!
The 19-th frame transmitted success!
The 20-th frame transmitted success!
1 frame has been successfuly received
2 frame has been successfuly received
3 frame has been successfuly received
4 frame has been successfuly received
5 frame has been successfuly received
6 frame has been successfuly received
9 frame has been successfuly received
10 frame has been successfuly received
12 frame has been successfuly received
13 frame has been successfuly received
14 frame has been successfuly received
15 frame has been successfuly received
17 frame has been successfuly received
18 frame has been successfuly received
19 frame has been successfuly received
20 frame has been successfuly received


...

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Customization options
=====================

