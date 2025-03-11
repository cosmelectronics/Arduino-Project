# PIR Sensor Interface with Arduino UNO

## Project Overview
This project demonstrates how to interface a **PIR (Passive Infrared) Sensor** with an **Arduino UNO**. The system detects motion using the PIR sensor and triggers a **red LED** as an output indication. Additionally, the motion status is printed on the **Serial Monitor**.

## Features
- **Motion Detection:** Uses a PIR sensor to detect movement.
- **Visual Indicator:** A red LED turns on when motion is detected.
- **Serial Monitoring:** The motion status is displayed on the Serial Monitor in real-time.

## Components Required
- **Arduino UNO**
- **PIR Sensor**
- **Red LED**
- **Resistor (220Ω)**
- **Jumper Wires**
- **Breadboard**

## Circuit Connections
| Component  | Arduino UNO Pin |
|------------|----------------|
| PIR Sensor (OUT) | D2 |
| Red LED (Anode)  | D13 |
| LED (Cathode)    | GND via 220Ω Resistor |
| PIR Sensor (VCC) | 5V |
| PIR Sensor (GND) | GND |

## Working Principle
1. The PIR sensor detects motion based on infrared radiation changes.
2. When motion is detected, it sends a **HIGH signal** to the Arduino.
3. The Arduino turns on the **LED** and prints "Motion Detected!" on the Serial Monitor.
4. When no motion is detected, the **LED** remains off, and "No Motion" is displayed.

## Usage Instructions
1. Connect the components as per the circuit diagram.
2. Upload the provided Arduino code to the **Arduino UNO**.
3. Open the **Serial Monitor** (9600 baud rate) to observe motion status.
4. Wave your hand in front of the PIR sensor to test the motion detection.

## Author
This project is designed by **Prince Kushwaha** from **COSM Electronics**.

## License
This project is open-source and can be modified and distributed for educational and personal use.
