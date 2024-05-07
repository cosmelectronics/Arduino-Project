# Arduino MQ-2 Gas Sensor with LCD Display

This project demonstrates how to interface an MQ-2 gas sensor with an Arduino Uno and display the sensor value on an LCD using an I2C module. 

## Components Used
- Arduino Uno
- MQ-2 Gas Sensor
- LCD Display (16x2) with I2C Module
- Jumper Wires

## Connections
- MQ-2 Sensor:
  - VCC to Arduino 5V
  - GND to Arduino GND
  - AO (Analog Output) to Arduino A0

- LCD Display with I2C Module:
  - VCC to Arduino 5V
  - GND to Arduino GND
  - SDA to Arduino A4
  - SCL to Arduino A5

## Code Explanation
- The code reads the analog output from the MQ-2 sensor connected to pin A0.
- It converts the analog value to voltage and prints it to the serial monitor.
- The LCD is initialized with the I2C address and dimensions (16 columns, 2 rows).
- The sensor value is displayed on the LCD along with the serial output.

## Author
This code is designed by Prince Kushwaha.
