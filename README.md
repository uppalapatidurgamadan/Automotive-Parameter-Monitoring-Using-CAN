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
| 💡 Indicator Control        | Control left/right indicators through CAN       |
| 📺 Dashboard Display        | Display vehicle parameters on 20×4 LCD        |
| 🔌 Distributed System       | Understand automotive embedded architecture      |

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

> **Note:** The CAN bus is terminated with **120Ω resistors at both ends** to eliminate signal reflections and ensure reliable communication.

---
<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/b204a19a-0f67-44a1-b00c-bcd4e0a4d184" />


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

<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/a9274bb6-a219-4c27-bca2-20708e70b20d" />

---

# ⛽ Fuel Node

## Functions

| Function          | Description                               |
| ----------------- | ----------------------------------------- |
| Fuel Measurement  | Reads fuel sensor                         |
| ADC Conversion    | Converts analog signal into digital value |
| CAN Transmission  | Sends fuel level to Main Node             |
| Periodic Update   | Continuously updates Main Node            |

### Fuel Node Workflow

<img width="1024" height="1536" alt="image" src="https://github.com/user-attachments/assets/f14a127c-ea27-457c-9ba1-6de48b4c3cde" />

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

<img width="1122" height="1402" alt="image" src="https://github.com/user-attachments/assets/46bb8087-c85c-4232-95aa-b39dcfc2ac81" />


---

# 🔌 Hardware Connections
<img width="1280" height="960" alt="WhatsApp Image 2026-08-02 at 2 12 11 PM" src="https://github.com/user-attachments/assets/0b3bbd79-0f88-49a2-9fd0-3b62287e1177" />

---

# ⭐ Key Features

| Feature                     | Description                         |
| --------------------------- | ----------------------------------- |
| Multi-node CAN Architecture | Three independent controller        |
| Real-time Monitoring        | Live vehicle parameter display      |
| Fuel Level Monitoring       | ADC-based                           |
| Temperature Monitoring      | DS18B20 based                       |
| Indicator Control           | CAN-controlled                      |
| Distributed Processing      | Multiple ECUs                       |
| Modular Design              | Easy to expand                      |
| Reliable Communication      | CAN error detection                 |

---

# 🚀 Advantages

| Benefit                 | Description                         |
| ----------------------- | ----------------------------------- |
| High Reliability        | Robust CAN communication            |
| Reduced Wiring          | Single shared CAN bus               |
| Fault Tolerance         | Built-in CAN error detection        |
| Real-time Communication | Fast Data transfer                  |
| Scalable Design         | Easy to add new ECUs                |
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

📁Project Folder Structure

Automotive-CAN-Bus-System/ \
│
├── Main_Node/\
│ ├── main.c\
│ ├── can.c\
│ ├── lcd.c\
│ ├── ds18b20.c\
│ ├── interrupt.c\
│ └── include/\
│\
├── Fuel_Node/\
│ ├── main.c\
│ ├── adc.c\
│ ├── can.c\
│ └── include /\
│\
├── Indicator_Node/\
│ ├── main.c\
│ ├── led.c\
│ ├── can.c\
│ └── include /\
│ \
├── README.md\
└── LICENSE\

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
<img width="1080" height="908" alt="WhatsApp Image 2026-08-02 at 2 19 11 PM" src="https://github.com/user-attachments/assets/d14242b9-a901-4f84-b664-74894596ed7e" />

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

* 💼 LinkedIn: *(https://linkedin.com/in/uppalapati-durga-madan-7324a132a)*

---

