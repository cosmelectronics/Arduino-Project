# Arduino RGB LED Control

This project demonstrates how to control a common anode RGB LED using an Arduino Uno. The code provided allows you to change the color of the RGB LED using different combinations of red, green, and blue intensities.

## Hardware Requirements

- Arduino Uno
- Common anode RGB LED
- Resistors (to limit current, if necessary)
- Jumper wires

## Circuit Diagram

- Attached in this file.

## Installation

1. Connect the common anode pin of the RGB LED to the 5V pin of the Arduino.
2. Connect the cathode pins of the RGB LED to digital pins 9 (red), 10 (green), and 11 (blue) on the Arduino.
3. Upload the provided Arduino sketch (RGB_LED_Control.ino) to your Arduino Uno.

## Usage

Once the sketch is uploaded to your Arduino Uno, the RGB LED will cycle through different colors in a loop:

1. Red
2. Green
3. Blue
4. Purple (Red + Blue)
5. Yellow (Red + Green)
6. Cyan (Green + Blue)
7. White (Red + Green + Blue)

The LED will stay each color for one second before moving to the next color.

Feel free to modify and adapt this code for your own projects!
