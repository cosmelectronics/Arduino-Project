# Arduino 7-Segment Display Interface

This project demonstrates how to interface a common anode 7-segment display with an Arduino to display digits 0-9 in a loop.

## Project Overview

A 7-segment display is a simple electronic display device that can display digits. In this project, we will connect a common anode 7-segment display to an Arduino and write code to display digits 0-9 sequentially.

## Components

- Arduino board (e.g., Arduino Uno)
- Common anode 7-segment display
- 8 current-limiting resistors (220Ω or 330Ω)
- Connecting wires
- Breadboard (optional, for easier connections)

## Wiring Diagram

| Segment | Arduino Pin |
| ------- | ------------ |
| a       | 2            |
| b       | 3            |
| c       | 4            |
| d       | 5            |
| e       | 6            |
| f       | 7            |
| g       | 8            |
| dp      | 9            |

- Connect the common anode pin of the display to the 5V pin on the Arduino.
- Connect each segment (a, b, c, d, e, f, g, dp) to the corresponding digital pin on the Arduino through a current-limiting resistor.

## How to Use

1. **Hardware Setup**: Connect the 7-segment display to the Arduino according to the wiring diagram above.
2. **Code Upload**: Upload the provided Arduino code to your Arduino board.
3. **Power Up**: Power the Arduino board. The 7-segment display will start showing digits 0-9 in a loop with a 1-second delay between each digit.

## Important Notes

- For a common anode display, setting a segment pin to LOW will turn the segment on, and setting it to HIGH will turn the segment off.
- Ensure you use current-limiting resistors to protect the LEDs in the 7-segment display from excessive current.

## Credits

This code is designed by Prince Kushwaha from COSM Electronics.

---

Feel free to reach out if you have any questions or need further assistance with this project. Happy coding!
