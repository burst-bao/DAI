Overview
========
This example shows how to use SDK drivers to use the Frequency Measure feature of SYSCON module on LPC devices.
It shows how to measure a target frequency using a (faster) reference frequency. The example uses the internal main clock as the reference frequency to measure the frequencies of the RTC, watchdog oscillator, and internal RC oscillator.

Toolchain supported
===================
- IAR embedded Workbench  8.40.2
- Keil MDK  5.29
- MCUXpresso  11.1.0
- GCC ARM Embedded  8.3.1

Hardware requirements
=====================
- Micro USB cable
- LPCLPCXpresso54608 board
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
The log below shows example output of the frequency measure demo in the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Capture source: Watchdog oscillator (main clock reference), reference frequency = 180000000 Hz
Computed frequency value = 582275 Hz
Expected frequency value = 500000 Hz

Capture source: RTC32K oscillator (main clock reference), reference frequency = 180000000 Hz
Computed frequency value = 21972 Hz
Expected frequency value = 32768 Hz

Capture source: FRO oscillator (main clock reference), reference frequency = 180000000 Hz
Computed frequency value = 11997070 Hz
Expected frequency value = 12000000 Hz
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Customization options
=====================

