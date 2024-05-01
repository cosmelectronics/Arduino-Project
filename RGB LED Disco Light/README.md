# RGB LED Disco Light

## Overview
This project creates a disco light effect using an RGB LED. It includes various modes such as static color, color fading, blinking, and random colors, which can be cycled through using a push button.

## Components Used
- RGB LED
- Push button
- Resistors (220 ohm for RGB LED, 10k ohm for push button)
- Jumper wires

## Circuit Connection
- Connect the red pin of the RGB LED to digital pin 9 on the Arduino via a 220 ohm resistor.
- Connect the green pin of the RGB LED to digital pin 10 on the Arduino via a 220 ohm resistor.
- Connect the blue pin of the RGB LED to digital pin 11 on the Arduino via a 220 ohm resistor.
- Connect one leg of the push button to digital pin 2 on the Arduino.
- Connect the other leg of the push button to the ground (GND) on the Arduino via a 10k ohm resistor.

## Modes
1. **Static Color**: The LED displays a static color (e.g., red).
2. **Color Fading**: The LED smoothly transitions through various colors.
3. **Blinking**: The LED alternates between white and off states.
4. **Random Colors**: The LED displays random colors.

## Usage
1. Connect the components according to the provided circuit diagram.
2. Upload the provided code to your Arduino board.
3. Press the push button to cycle through different disco light modes.

## Author
Designed by Prince Kushwaha
