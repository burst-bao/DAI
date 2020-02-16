Overview
========
The mcan_interrupt example shows how to use MCAN driver in none-blocking interrupt way:

In this example, 2 boards are connected through CAN bus. Endpoint A(board A) send a CAN Message to
Endpoint B(board B) when users press space key in terminal. Endpoint B receives the message, prints
the message content to terminal and echoes back the message. Endpoint A will increase the received
message and wait for the next transmission the users initiate.

Toolchain supported
===================
- IAR embedded Workbench  8.40.2
- Keil MDK  5.29
- MCUXpresso  11.1.0
- GCC ARM Embedded  8.3.1

Hardware requirements
=====================
- Two Micro USB cables
- Two LPCXpresso54608 boards
- CAN Transceiver
- Personal Computer

Board settings
==============
Since LPCXpresso54608 has no CAN transceiver on board, extra circuits and CAN transceivers are needed.
The connection should be set as follows:
Between board and Transceiver:
- J10-2, transceiver RXD connected
- J10-4, transceiver TXD connected
Between CAN transceivers:
- CANH, CANL, GND should be connected

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
One board must be chosen as node A and the other board as node B. (Note: Node B should start first)
Data is sent continuously between node A and node B.

~~~~~~~~~~~~~~~~~~~~~
This message displays on the node A terminal:

Please select local node as A or B:
Note: Node B should start first.
Node:a
Press any key to trigger one-shot transmission

Received Frame ID: 0x123
Received Frame DATA: 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 
Press any key to trigger the next transmission!

Received Frame ID: 0x123
Received Frame DATA: 0x1 0x1 0x2 0x3 0x4 0x5 0x6 0x7 
Press any key to trigger the next transmission!

This message displays on the node B terminal:

Please select local node as A or B:
Note: Node B should start first.
Node:b
Start to Wait data from Node A

Received Frame ID: 0x321
Received Frame DATA: 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 
Wait Node A to trigger the next transmission!

Received Frame ID: 0x321
Received Frame DATA: 0x1 0x1 0x2 0x3 0x4 0x5 0x6 0x7 
Wait Node A to trigger the next transmission!
~~~~~~~~~~~~~~~~~~~~~
Customization options
=====================

