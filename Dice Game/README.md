# Arduino Dice Roller Project

This Arduino project simulates rolling a dice using an Arduino board along with various components like an LCD, push button, buzzer, and RGB LED.

## Description

The project uses an Arduino board along with the following components:

- 16x2 LCD display (connected via I2C)
- Push button
- Buzzer
- RGB LED

The project creates a virtual dice that rolls when the push button is pressed. The LCD displays the current and final random number generated during the roll. The RGB LED glows with a random color while the dice is rolling, and the buzzer plays a short tone when the final number is generated.

## Circuit Diagram

- Attached in the folder.

## Connections

- LCD: Connect SDA and SCL pins to the corresponding SDA and SCL pins on the Arduino board.
- Push button:
  - Connect one leg of the push button to digital pin 2 on the Arduino.
  - Connect the other leg of the push button to ground (GND) on the Arduino.
  - Optionally, connect a 10k ohm resistor between the pin connected to the push button and the ground to avoid floating input when the button is not pressed.
- Buzzer: Connect the positive terminal of the buzzer to a digital pin on the Arduino (e.g., pin 7) and the negative terminal to ground.
- RGB LED: Connect the red, green, and blue pins of the RGB LED to digital pins on the Arduino (e.g., pins 9, 10, and 8) respectively. Connect the common cathode/anode to ground.

## Setup

1. Connect the components as per the circuit diagram and the mentioned connections.
2. Upload the provided Arduino code to your Arduino board.
3. Press the push button to roll the virtual dice.

## Credits

This project was designed by Prince Kushwaha.
