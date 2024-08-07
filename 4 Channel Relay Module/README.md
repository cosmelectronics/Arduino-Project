# Relay Control Project

This project demonstrates how to control a relay module using an Arduino. The relay module allows you to control high-voltage devices like lights, fans, or other household appliances using the low-voltage digital output from the Arduino.

## Features

- Control up to four relays using digital pins.
- Each relay can be turned on for a specified duration and then turned off.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno)
- Relay module (4-channel)
- Jumper wires
- Breadboard (optional for neat wiring)

## Pin Connections

- Relay IN1 connected to Arduino pin 2
- Relay IN2 connected to Arduino pin 3
- Relay IN3 connected to Arduino pin 4
- Relay IN4 connected to Arduino pin 5

## Setup Instructions

1. **Hardware Setup:**
   - Connect the IN1, IN2, IN3, and IN4 pins of the relay module to the corresponding digital pins on the Arduino (pins 2, 3, 4, and 5).
   - Connect the VCC and GND pins of the relay module to the 5V and GND pins on the Arduino.

2. **Software Setup:**
   - Open the Arduino IDE on your computer.
   - Create a new sketch and copy the provided code into the IDE.
   - Connect your Arduino board to your computer using a USB cable.
   - Select the correct board and port from the Arduino IDE.
   - Upload the sketch to the Arduino board.

## Usage

Once the sketch is uploaded, the Arduino will control the relays in a sequence:

- Each relay will turn on for 1 second and then turn off for 1 second.
- This sequence will repeat indefinitely.

## License

This code is designed by Prince Kushwaha from COSM Electronics.
