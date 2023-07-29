# EEPROM_programming_Arduino
In this project we are aiming to reprogram and infected e2prom with Arduino IDE. The bits and their relative registers should be written regarding to your objectives. 
## EEPROM Registers
The project is based on DS2430A - Dallas Semiconductor which uses 1-Wire communication (you easily can find its datasheet online). The relative control commands and initializing circuits are extracted from the datasheet, and <OneWire.h> library has been used to transfer commands and data bits to the EEPROM. 
## Instructions
### Hardware
Aruino UNO R3 with serial communication and below circuit diagram has been used for running and testing the codes. Remember that pull-up/down resistors and capacitors' values may vary regarding to your IC models and manuals.

<p align="center">
<img src="https://github-production-user-asset-6210df.s3.amazonaws.com/108813301/256978038-54d77738-49c5-4aa4-90d3-dfca49caee07.png" width="400" height="320" />
</p>

### Software
As we are aiming to reprogram the infected IC, at first, by calling the address bits (specified in the datasheet), we check whether it is burned out or not. Then, we call and read the Status Register to find out what mode the e2prom is working on (this step could be used to identify some probable disfunctionalities). After that, we write/read our desired data bits on/from the scratchpad. Finally, we permanently write and store data bits to our ideal storage adderess. Remember to test and re-read the written data after switching off/on with 10 or 5 minutes delay, in order to make sure your EEPROM can store and hold data bits without any problem.  

In short the steps are:
1) Search & check for EEPROM connection (present at first part of the codes)
2) Read Status Register
3) Write/Read Registers (optional)
4) Write/Read Scratchpad
5) Write/Read Memory


***
*you can find the raw Arduino codes for each step in the repository*
