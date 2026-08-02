# 🚗 Automotive Parameter Monitoring System Using CAN Protocol

## 📌 Project Overview

Modern vehicles rely on multiple Electronic Control Units (ECUs) to manage different functions efficiently. Instead of using separate wiring between every controller, these ECUs exchange information through a Controller Area Network (CAN), which reduces wiring complexity and enables reliable real-time communication.

Each node performs a dedicated task:

Main Node – Controls the overall system, monitors temperature, receives fuel level data, and controls vehicle indicators.\
Fuel Node – Reads fuel level using ADC and transmits fuel information.\
Indicator Node – Receives turn indicator commands and displays LED scrolling patterns.

All nodes communicate through the CAN protocol using the on-chip CAN controller of LPC2129 and the MCP2551 CAN transceiver.

---

# 🎯 Objectives

| Objective                   | Description                                   |
| --------------------------- | --------------------------------------------- |
| 🚗 Learn CAN Protocol       | Understand CAN communication between ECUs     |
| 🔄 Multi-node Communication | Implement three-node CAN network              |
| 🌡 Temperature Monitoring   | Measure engine temperature using DS18B20      |
| ⛽ Fuel Monitoring           | Measure fuel level using ADC                  |
| 💡 Indicator Control        | Control turn indicators through CAN           |
| 📺 Dashboard Display        | Display vehicle parameters on 20×4 LCD        |
| ⚡ Real-time Communication   | Exchange data between nodes in real time      |
| 🧩 Embedded System Design   | Develop a distributed automotive architecture |

---

# 🧰 Hardware Components

| Component                   | Quantity | Purpose                            |
| --------------------------- | -------- | ---------------------------------- |
| LPC2129 ARM7 MCU            | 3        | Controller for each CAN node       |
| MCP2551 CAN Transceiver     | 3        | CAN physical layer communication   |
| DS18B20 Temperature Sensor  | 1        | Engine temperature measurement     |
| Fuel Sensor (Potentiometer) | 1        | Fuel level simulation              |
| 20×4 LCD                    | 1        | Display temperature and fuel level |
| Push Buttons                | 2        | Left and Right indicator control   |
| LEDs                        | 8        | Indicator simulation               |
| 120Ω Resistors              | 2        | CAN bus termination                |
| Crystal Oscillator          | 3        | MCU clock generation               |
| 5V/3.3V Power Supply        | 1        | System power                       |

---

# 💻 Software Requirements

| Software           | Purpose                |
| ------------------ | ---------------------- |
| Keil µVision 4     | Embedded C Development |
| Embedded C         | Programming Language   |
| Flash Magic        | Program Download       |
| Proteus (Optional) | Circuit Simulation     |

> **Note:** The CAN bus is terminated with **120Ω resistors at both ends** to eliminate signal reflections and ensure reliable communication.

---

# 🏗 System Architecture

```text
                    CAN BUS
-------------------------------------------------------

        +--------------------+
        |    Main Node       |
        |--------------------|
        | LPC2129            |
        | LCD                |
        | DS18B20            |
        | Push Buttons       |
        +---------+----------+
                  |
                  |
      -----------------------------
      |                           |
      |                           |
+-----+------+             +------+------+
| Fuel Node  |             | Indicator   |
|-------------|            | Node        |
| LPC2129     |            | LPC2129     |
| ADC         |            | LEDs        |
| Fuel Sensor |            |             |
+-------------+            +-------------+
```

---

# 🚘 Main Node

## Functions

| Function                  | Description                            |
| ------------------------- | -------------------------------------- |
| 🌡 Temperature Monitoring | Reads engine temperature using DS18B20 |
| 📺 LCD Display            | Displays temperature and fuel level    |
| 📩 CAN Receiver           | Receives fuel level from Fuel Node     |
| 💡 Indicator Control      | Reads left/right switch status         |
| 📤 CAN Transmitter        | Sends indicator commands               |
| 🧠 Network Coordinator    | Manages overall CAN communication      |

### Main Node Workflow

```text
Start
   │
Initialize LCD
   │
Initialize CAN
   │
Initialize DS18B20
   │
Read Temperature
   │
Receive Fuel Data
   │
Display Temperature & Fuel
   │
Read Indicator Switches
   │
Transmit Indicator Command
   │
Repeat
```

---

# ⛽ Fuel Node

## Functions

| Function          | Description                               |
| ----------------- | ----------------------------------------- |
| Fuel Measurement  | Reads fuel sensor                         |
| ADC Conversion    | Converts analog signal into digital value |
| Fuel Calculation  | Calculates fuel percentage                |
| CAN Transmission  | Sends fuel level to Main Node             |
| Continuous Update | Periodically transmits data               |

### Fuel Node Workflow

```text
Start
   │
Initialize ADC
   │
Initialize CAN
   │
Read Fuel Sensor
   │
Convert ADC Value
   │
Calculate Fuel %
   │
Transmit Fuel Data
   │
Repeat
```

---

# 💡 Indicator Node

## Functions

| Function        | Description                |
| --------------- | -------------------------- |
| CAN Receiver    | Receives indicator command |
| LED Control     | Drives LEDs                |
| Left Indicator  | Right → Left scrolling     |
| Right Indicator | Left → Right scrolling     |

### Indicator Node Workflow

```text
Start
   │
Initialize CAN
   │
Wait for CAN Message
   │
Receive Indicator Command
   │
Drive LEDs
   │
Repeat
```

---

# 🔌 Hardware Connections

## Main Node

* LPC2129
* MCP2551 CAN Transceiver
* DS18B20 Temperature Sensor
* 20×4 LCD
* Left & Right Push Buttons

## Fuel Node

* LPC2129
* MCP2551
* Potentiometer (Fuel Sensor)
* ADC Channel

## Indicator Node

* LPC2129
* MCP2551
* 8 LEDs

---

# ⭐ Key Features

| Feature                     | Description                         |
| --------------------------- | ----------------------------------- |
| Multi-node CAN Architecture | Three independent ECUs              |
| Real-time Monitoring        | Live vehicle data                   |
| Fuel Level Monitoring       | ADC-based measurement               |
| Temperature Monitoring      | DS18B20 sensor                      |
| Indicator Control           | CAN-controlled LED indicators       |
| Distributed Processing      | Multiple controllers                |
| Modular Design              | Easy to expand                      |
| Reliable Communication      | CAN error detection and arbitration |

---

# 🚀 Advantages

| Benefit                 | Description                         |
| ----------------------- | ----------------------------------- |
| High Reliability        | Robust CAN communication            |
| Reduced Wiring          | Single shared CAN bus               |
| Fault Tolerance         | Built-in CAN error detection        |
| Real-time Communication | Fast message transfer               |
| Scalable Design         | Easy to add more ECUs               |
| Priority Arbitration    | Critical messages transmitted first |

---

# 🚙 Applications

* 🚗 Passenger Vehicles
* ⚡ Electric Vehicles (EVs)
* 🚜 Agricultural Machines
* 🚚 Heavy Trucks
* 🏭 Industrial Automation
* 🚢 Marine Systems
* 🚦 Smart Transportation
* 🎓 Automotive Education

---



# 📺 Output

| Module       | Output                                   |
| ------------ | ---------------------------------------- |
| Main Node    | Displays engine temperature              |
| Fuel Node    | Continuously transmits fuel percentage   |
| Main Node    | Receives and displays fuel level         |
| Left Switch  | LEDs scroll Right → Left                 |
| Right Switch | LEDs scroll Left → Right                 |
| CAN Bus      | Reliable communication between all nodes |

---

# 📷 Project Images

Add your images in the `Images/` folder and reference them like this:

```markdown
## Hardware Setup

![Hardware Setup](Images/Hardware_Setup.jpg)

## Main Node

![Main Node](Images/Main_Node_Output.jpg)

## Fuel Node

![Fuel Node](Images/Fuel_Node_Output.jpg)

## Indicator Node

![Indicator Node](Images/Indicator_Output.jpg)
```

---

# 🔮 Future Enhancements

* 🚗 Vehicle speed monitoring
* 🛢️ Engine oil level monitoring
* 🔋 Battery voltage monitoring
* 🌐 IoT-based remote monitoring
* 📱 Mobile application interface
* 📍 GPS integration
* ⚠️ Fault diagnostics and DTC logging
* 📈 Data logging to SD card

---

# 👨‍💻 Author

**Uppalapati Durga Madan**

* 🎓 B.Tech – Electronics & Communication Engineering
* 💻 Embedded Systems Engineer
* 🔧 Skills: Embedded C, ARM7, CAN, UART, SPI, I²C, RTOS, LPC2129
* 🌐 GitHub: `https://github.com/your-username` *(replace with your profile link)*
* 💼 LinkedIn: *(add your LinkedIn profile link)*

---

This README follows GitHub best practices, is ATS-friendly, and presents your embedded project in a professional format suitable for recruiters and interviewers.
