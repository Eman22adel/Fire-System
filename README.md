# Fire-System
This project is designed to create a fire detection and alert system using two Microcontroller Units (MCUs): a Master MCU and a Slave MCU. 

## Project Description
The project implements the following drivers:
- Keypad
- LCD
- UART
- Timer
- EEPROM

These drivers allow the system to interact with the user, display information, communicate between the MCUs, manage timing operations, and store data respectively.

The system operates in two modes: Normal mode and Fire mode.

1. **Normal Mode**: In this mode, the second microcontroller displays "No Receive" on the LCD. This indicates that no fire has been detected and the system is operating normally.

2. **Fire Mode**: This mode is activated when a fire is detected. The system continues in this mode until the user enters the correct password via the keypad. If the user does not press any button within 8000 milliseconds, the system assumes that the user is outside the house. In such a case, the system sends the location to the fire station (second microcontroller) using the UART communication protocol. The second microcontroller then displays the received location on the LCD.

This system ensures that in the event of a fire, the fire station is alerted as quickly as possible, potentially saving lives and property.

