Overview
========
The spi_interrupt example shows how to use spi functional API to do interrupt transfer:

In this example, one spi instance as master and another spi instance as slave. Master sends a piece of data to slave,
and check if the data slave received is correct.

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
SPI one board:
Transfer data from instance0 to instance 1 of SPI interface.
SPI9 pins are connected with SPI3 pins of board
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
INSTANCE0(SPI9)     CONNECTS TO         INSTANCE1(SPI3)
Pin Name   Board Location     Pin Name  Board Location
MISO       J9 pin 11          MISO      J14 pin 3
MOSI       J9 pin 13          MOSI      J14 pin 2
SCK        J9 pin 9           SCK       J14 pin 4
PCS0       J9 pin 15          PCS0      J14 pin 1

Make sure JP-6 is fitted to use the PMOD SPI port.
Also in JP8 pin 1-3 and 7-9 should be shorted.
Change the solder jumper JS27 to 2-3 to use P3_30 pin as SSEL or
to use the Arduino connector J9 Pin 15.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Prepare the Demo
================
1.  Connect a micro USB cable between the PC host and the LPC-Link USB port (J8) on the board.
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Reset the SoC and run the project.

Running the demo
================
When the demo runs successfully, the log would be seen on the terminal like:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SPI one board interrupt example started!

SPI transfer finished!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Customization options
=====================

