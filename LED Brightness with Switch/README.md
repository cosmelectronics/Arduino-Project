# Arduino LED Brightness Control with Push Button

## Overview
This project demonstrates how to control the brightness of an LED using a push button with an Arduino. When the button is pressed, the brightness of the LED increases. If the brightness exceeds the maximum value (255), it resets to zero.

## Components Used
- Arduino board
- Push button
- LED
- 220 ohm resistor (for LED)
- Jumper wires

## Circuit Connection
- Connect one leg of the push button to digital pin 2 on the Arduino.
- Connect the other leg of the push button to ground (GND) on the Arduino.
- Connect a 10k ohm resistor between the pin connected to the push button and the ground to avoid floating input when the button is not pressed.
- Connect the long leg (anode) of the LED to PWM pin 9 on the Arduino via a 220 ohm resistor.
- Connect the short leg (cathode) of the LED to ground (GND) on the Arduino.

## Usage
1. Connect the components according to the provided circuit diagram.
2. Upload the provided code to your Arduino board.
3. Press the push button to increase the brightness of the LED.
4. If the brightness exceeds 255, it will reset to zero.

## Author
Designed by Prince Kushwaha
