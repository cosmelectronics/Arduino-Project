# Arduino Push Button LED Toggle

This project demonstrates how to toggle an LED on and off using a push button with an Arduino.

## Components Used
- Red LED
- 220 ohm resistor (for LED)
- 10k ohm resistor (for push button)
- Push button
- Arduino board

## Circuit Connection
The circuit consists of a push button and an LED connected to an Arduino board. The push button is connected to digital pin 2, and the LED is connected to digital pin 13. The components are connected as follows:

- Connect one leg of the push button to digital pin 2 on the Arduino.
- Connect the other leg of the push button to ground (GND) on the Arduino.
- Optionally, connect a 10k ohm resistor between the pin connected to the push button and the ground to avoid floating input when the button is not pressed.
- Connect the long leg (anode) of the LED to digital pin 13 on the Arduino via a 220 ohm resistor.
- Connect the short leg (cathode) of the LED to ground (GND) on the Arduino.

## Usage
1. Connect the components according to the provided circuit diagram.
2. Upload the provided code to your Arduino board.
3. Press the push button to toggle the LED on and off.

## Author
Designed by Prince Kushwaha

## Video Link
Watch Full Video on YouTube: Click Here
