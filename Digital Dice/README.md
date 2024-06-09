# Digital Dice with 7-Segment Display and Push Button Control

This project is designed by Prince Kushwaha from COSM Electronics. It demonstrates how to create a digital dice using a 7-segment display controlled by an Arduino and a push button. The display shows a random number between 1 and 6 when the button is pressed, and it also displays a moving pattern when the button is not pressed.

## Components

- Arduino
- 7-segment display
- Push button
- Resistors
- Jumper wires
- Breadboard

## Circuit Connections

1. **7-Segment Display:**
    - Connect segment `a` to Arduino pin 2.
    - Connect segment `b` to Arduino pin 3.
    - Connect segment `c` to Arduino pin 4.
    - Connect segment `d` to Arduino pin 5.
    - Connect segment `e` to Arduino pin 6.
    - Connect segment `f` to Arduino pin 7.
    - Connect segment `g` to Arduino pin 8.

2. **Push Button:**
    - Connect one side of the push button to Arduino pin 9.
    - Connect the other side of the push button to ground.
    - Use a pull-up resistor for the push button connection to ensure a stable input.

3. **Power:**
    - Connect the VCC of the 7-segment display to the 5V pin on the Arduino.
    - Connect the GND of the 7-segment display to the GND pin on the Arduino.

## Usage

1. Upload the provided code to your Arduino.
2. Connect the 7-segment display and the push button as per the circuit connections.
3. When the Arduino is powered on, the 7-segment display will show a moving pattern.
4. Press the button to display a random number between 1 and 6.

---

Designed by Prince Kushwaha from COSM Electronics
```
