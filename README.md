🚗Automotive-Parameter-Monitoring-Using-CAN
📌 Project Overview

Modern automobiles contain several Electronic Control Units (ECUs) that communicate through the CAN Bus instead of individual point-to-point wiring. This project simulates such an automotive network by implementing three independent CAN nodes connected through a common CAN bus.

Each node performs a dedicated task:

Main Node – Controls the overall system, monitors temperature, receives fuel level data, and controls vehicle indicators.
Fuel Node – Reads fuel level using ADC and transmits fuel information.
Indicator Node – Receives turn indicator commands and displays LED scrolling patterns.

All nodes communicate through the CAN protocol using the on-chip CAN controller of LPC2129 and the MCP2551 CAN transceiver.

🎯 Objectives

Objective	Description
🚗 CAN Communication	Learn Controller Area Network protocol
🔄 Multi-node System	Implement communication between multiple ECUs
🌡 Sensor Interface	Read engine temperature using DS18B20
⛽ Fuel Monitoring	Measure fuel level using ADC
💡 Indicator Control	Control left/right indicators through CAN
📺 Dashboard Display	Display vehicle parameters on LCD
🔌 Distributed System	Understand automotive embedded architecture
🧰 Hardware Components

Component	Quantity	Purpose
LPC2129 ARM7 MCU	3	Main controller for each node
MCP2551 CAN Transceiver	3	CAN physical layer
DS18B20 Temperature Sensor	1	Engine temperature measurement
Fuel Sensor(potentiometer)	1	Fuel level simulation
LCD (20X4)	1	Display temperature & fuel
Push Buttons	2	Left & Right indicator control
LEDs	8	Indicator simulation
120Ω Resistors	2	CAN bus termination
Crystal Oscillator	3	MCU clock generation
5V/3.3V Supply	1	Power source
💻 Software Requirements

Software	Purpose
Keil µVision 4	Code Development
Embedded C	Programming Language
Flash Magic	Program Download
CAN is terminated with 120Ω resistors at both ends to eliminate signal reflections.
WhatsApp Image 2026-07-21 at 7 20 58 PM

🚘 Main Node

Function	Description
🌡 Temperature Monitoring	Reads engine temperature
📺 LCD Display	Displays temperature & fuel level
📩 CAN Receiver	Receives fuel level from Fuel Node
💡 Indicator Control	Reads switch status
📤 CAN Transmitter	Sends indicator commands
🧠 Network Controller	Coordinates all CAN communication
main node work flow

ChatGPT Image Jul 21, 2026, 11_55_26 AM
⛽Fuel Node

Function	Description
Fuel Measurement	Reads analog fuel level
ADC Conversion	Converts analog to digital
CAN Transmission	Sends fuel percentage
Periodic Update	Continuously updates Main Node
fuel node work flow

ChatGPT Image Jul 21, 2026, 11_43_18 AM
💡Indicator Node

Function	Description
CAN Receiver	Receives indicator command
LED Control	Drives LEDs
Left Animation	Right → Left scrolling
Right Animation	Left → Right scrolling
Indicator node work flow

ChatGPT Image Jul 18, 2026, 04_57_21 PM
Hardware Connections

WhatsApp Image 2026-07-15 at 4 09 29 PM (1)
⭐Key Features

Feature	Description
Multi-node CAN Architecture	Three independent controllers
Real-time Monitoring	Live vehicle parameter display
Fuel Level Monitoring	ADC based
Temperature Monitoring	DS18B20 based
Indicator Control	CAN controlled
Distributed Processing	Multiple ECUs
Modular Design	Easy to expand
Reliable Communication	CAN Error Detection
🚀Advantages

Benefit	Description
High Reliability	Robust CAN communication
Reduced Wiring	Single CAN network
Fault Tolerance	CAN Error Detection
Real-time Communication	Fast data transfer
Expandable	Easy to add new nodes
Priority Arbitration	Critical messages transmitted first
🚙Applications

Application
Passenger Vehicles
Electric Vehicles
Agricultural Machines
Heavy Trucks
Industrial Automation
Marine Systems
Smart Transportation
Automotive Education
📁Project Folder Structure

Automotive-CAN-Bus-System/
│
├── Main_Node/
│ ├── main.c
│ ├── can.c
│ ├── lcd.c
│ ├── ds18b20.c
│ ├── interrupt.c
│ └── include/
│
├── Fuel_Node/
│ ├── main.c
│ ├── adc.c
│ ├── can.c
│ └── include /
│
├── Indicator_Node/
│ ├── main.c
│ ├── led.c
│ ├── can.c
│ └── include /
│
├── README.md
└── LICENSE

📺 Output

Module	Output
Main Node	Displays engine temperature
Fuel Node	Sends fuel percentage continuously
Main Node	Receives and displays fuel level
Left Switch	LEDs scroll Right → Left
Right Switch	LEDs scroll Left → Right
CAN Bus	Reliable communication between all nodes
WhatsApp Image 2026-07-15 at 4 06 34 PM
👨‍💻Author
