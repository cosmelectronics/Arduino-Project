# Arduino LED Control with Push Button

This project is designed by Prince Kushwaha from COSM Electronics.

## Project Overview

This Arduino-based project demonstrates how to control an LED using a push button. When the button is pressed, the LED lights up; when the button is released, the LED turns off. The project uses a simple circuit with an Arduino board, a push button, and an LED.

## Components

- Arduino board (e.g., Arduino Uno)
- Push button
- LED
- 220 ohm resistor
- 10k ohm resistor (optional, for button debounce)
- Breadboard and jumper wires

## Circuit Connections

### Push Button

1. **Connect one leg of the push button to digital pin 12** on the Arduino.
2. **Connect the other leg of the push button to ground (GND)** on the Arduino.
3. Optionally, **connect a 10k ohm resistor** between the pin connected to the push button and ground to avoid floating input when the button is not pressed.

### LED

1. **Connect the long leg (anode) of the LED to digital pin 8** on the Arduino via a 220 ohm resistor.
2. **Connect the short leg (cathode) of the LED to ground (GND)** on the Arduino.

## Usage

1. **Setup the circuit** as described in the connections section.
2. **Upload the provided code** to your Arduino board.
3. **Open the Serial Monitor** in the Arduino IDE to view the button state.
4. **Press the push button** to turn the LED on and release it to turn the LED off.

## Notes

- Ensure all connections are secure and the components are correctly oriented to prevent damage.
- The optional 10k ohm resistor helps to stabilize the button input by avoiding floating states when the button is not pressed.

This project is a basic example of how to interface an LED and a push button with an Arduino, useful for beginners to understand digital input and output operations.
