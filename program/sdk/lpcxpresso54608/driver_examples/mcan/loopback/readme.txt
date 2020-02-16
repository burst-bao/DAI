Overview
========
The mcan_loopback example shows how to use the loopback test mode to debug your CAN Bus design:

To demonstrate this example, only one board is needed. The example will config Tx Buffer to send
and Rx Fifo to receive. After that, the example will send a CAN Message throuth internal loopback
interconnect and print out the Message payload to the terminal.

Toolchain supported
===================
- IAR embedded Workbench  8.40.2
- Keil MDK  5.29
- MCUXpresso  11.1.0
- GCC ARM Embedded  8.3.1

Hardware requirements
=====================
- Micro USB cable
- LPCXpresso54608 board
- Personal Computer

Board settings
==============
No special settings are required.

Prepare the Demo
================
1.  Connect a micro USB cable between the host PC and the LPC-Link USB port (J8) on the target board.
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
The log below shows example output in the terminal window:
 
==MCAN loopback functional example -- Start.==

Received Frame ID: 0x123
Received Frame DATA: 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 

==MCAN loopback functional example -- Finish.==
Customization options
=====================

