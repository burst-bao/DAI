Overview
========
The uart synchronous transfer master example shows how to use usart driver in synchronous way:

In this example, one USART is configured as master node and another is configured as slave node.
Master will send data to slave firstly, and then receive data from slave, slave board will send back
the received data.

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
Please connect pins as below shows:
    Master board            Slave board
	J14-3(U3_RXD)  -----    J14-2(U3_TXD)
	J14-2(U3_TXD)  -----    J14-3(U3_RXD)
	J14-4(U3_SCLK) -----    J14-4(U3_SCLK)
	J14-5(GND)     -----    J14-5(GND)
Note that, please start slave board first.

Make sure JP-6 is fitted to use the PMOD port.
Also in JP8 pin 1-3 and 7-9 should be shorted.

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
When the demo runs successfully, the log would be seen on the terminal like:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
This is USART synchronous transfer master example.
Master will send data to slave firstly, and then receive data from slave.
Please connect the pins as below shows:
   Master Board          Slave Board
   USART_TX      -------   USART_RX
   USART_RX      -------   USART_TX
   USART_SCLK    -------   USART_SCLK
   GND           -------   GND
Transfer Complete. The data received from slave are:

 0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07 0x08 0x09 0x0A 0x0B 0x0C 0x0D 0x0E 0x0F

Data transfer matched!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Customization options
=====================

