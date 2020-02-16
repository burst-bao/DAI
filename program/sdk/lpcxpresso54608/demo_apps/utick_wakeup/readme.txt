Overview
========
The purpose of this demo is to show wakeup from deep sleep mode using MicroTick timer.
The demo sets the MicroTick Timer as a wake up source and puts the device in deep-sleep mode. 
The MicroTick timer wakes up the device. 

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
1. Pin P3_12 is used as a CLKOUT signal. Connect this pin to an Oscilloscope for viewing the signal. 

Prepare the Demo
================

Running the demo
================
The demo sets the MicroTick Timer as a wake up source and puts the device in deep-sleep mode. 
The MicroTick timer wakes up the device. After wake up the LED3 on the board blinks and a 
CLKOUT signal can be seen on pin P3_12.
The demo is not recommended to use debug mode In MCUXpresso, POWER_EnterDeepSleep () will 
kill the debug session.
Customization options
=====================

