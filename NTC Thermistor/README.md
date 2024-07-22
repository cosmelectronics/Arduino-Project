# NTC Thermistor Temperature Measurement with LCD Display

This project reads the temperature from an NTC thermistor using an Arduino, calculates the temperature, and displays it on a 16x2 LCD using the I2C protocol.

## Table of Contents
- [Introduction](#introduction)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction
This project demonstrates how to interface an NTC thermistor with an Arduino to measure temperature. The temperature is then displayed on a 16x2 LCD using an I2C module. The code takes multiple samples to get an accurate reading and uses the Steinhart-Hart equation to calculate the temperature from the resistance of the thermistor.

## Components
- Arduino Uno (or any compatible board)
- NTC Thermistor (10kΩ at 25°C)
- 10kΩ Resistor
- 16x2 LCD with I2C module
- Breadboard and jumper wires

## Circuit Diagram
Below is the circuit diagram for the project:

- Connect the LCD to the Arduino using I2C pins:
  - VCC to 5V
  - GND to GND
  - SDA to A4
  - SCL to A5

- Connect the voltage divider circuit to the Arduino:
  - One end of the 10kΩ resistor to 5V
  - The junction between the resistor and the thermistor to A0
  - The other end of the thermistor to GND
  - `vd_power_pin` (defined as pin 2) to control the voltage divider

## Installation
1. Clone this repository or download the ZIP file.
2. Open the Arduino IDE and install the `LiquidCrystal_I2C` library from the Library Manager.
3. Open the project file in the Arduino IDE.

## Usage
1. Connect the components as described in the Circuit Diagram section.
2. Upload the code to the Arduino board.
3. Open the Serial Monitor to see the ADC readings, thermistor resistance, and calculated temperature.
4. The temperature will also be displayed on the 16x2 LCD.

## Contributing
Contributions are welcome! If you have any suggestions or improvements, please create a pull request or open an issue.
