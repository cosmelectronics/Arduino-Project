# Ultrasonic Distance Measurement with Arduino and LCD

This project demonstrates how to measure distance using an ultrasonic sensor with an Arduino and display the readings on a 16x2 LCD via I2C communication.

## Description

This Arduino sketch measures distance using an ultrasonic sensor connected to the Arduino board. It calculates the distance based on the time it takes for the ultrasonic pulse to travel to the object and back. The distance is then displayed on a 16x2 LCD screen using the LiquidCrystal_I2C library for I2C communication.

## Setup and Connections

### Components Required:
- Arduino board (e.g., Arduino Uno)
- Ultrasonic sensor (HC-SR04)
- 16x2 LCD display module with I2C adapter
- Jumper wires

### Connections:
- **Ultrasonic Sensor:**
  - VCC pin to Arduino 5V
  - GND pin to Arduino GND
  - Trig pin (trigger) to Arduino digital pin 5
  - Echo pin to Arduino digital pin 6

- **LCD Display:**
  - SDA pin to Arduino analog pin A4
  - SCL pin to Arduino analog pin A5
  - VCC pin to Arduino 5V
  - GND pin to Arduino GND

## Formula for Calculating Distance
The distance is calculated using the formula:

```cpp
Distance (cm) = (Pulse duration * Speed of sound in air) / 2
```

Where:
- `Pulse duration` is the time taken for the ultrasonic pulse to travel to the object and back, measured in microseconds.
- `Speed of sound in air` is the speed of sound in air, approximately 0.034 cm/microsecond.

## Author
This code was designed by Prince Kushwaha.

For detailed implementation, refer to the code in the repository.

*Note: Adjustments might be necessary depending on specific hardware configurations.*
