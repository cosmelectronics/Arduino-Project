# Arduino 12-Hour Clock with AM/PM and 16x2 LCD

This project demonstrates how to create a simple 12-hour clock with AM/PM using an Arduino Uno and a 16x2 LCD with I2C interface. Users can input the initial time via the Serial Monitor in the HH:MM:SS AM/PM format, and the clock will keep track of time and display it on the LCD.

## Components Needed

- Arduino Uno
- 16x2 LCD with I2C backpack
- Breadboard and jumper wires

## Wiring

- Connect the SDA pin of the LCD to the A4 pin of the Arduino.
- Connect the SCL pin of the LCD to the A5 pin of the Arduino.
- Connect the VCC pin of the LCD to the 5V pin of the Arduino.
- Connect the GND pin of the LCD to the GND pin of the Arduino.

## Libraries Required

Make sure to install the following libraries in the Arduino IDE:

- `Wire.h` (usually comes pre-installed with Arduino IDE)
- `LiquidCrystal_I2C.h` (install from the Library Manager)

## Setup

1. **Connect the hardware** as described in the wiring section.
2. **Install the required libraries** in the Arduino IDE.
3. **Upload the provided code** to the Arduino.

## Usage

1. Open the Serial Monitor (set the baud rate to 9600).
2. Enter the current time in the HH:MM:SS AM/PM format (e.g., `03:45:30 PM`) and press Enter.
3. The LCD will display the entered time in 12-hour format with AM/PM and will update it every second.

## Example

When the Serial Monitor is opened, you will see:

```
Enter time:
HH:MM:SS AM/PM
```

Enter the time like this:

```
03:45:30 PM
```

The LCD will then display:

```
Time: 03:45:30 PM
```

and will keep updating every second.

## Notes

- The time input format must be strictly followed (HH:MM:SS AM/PM).
- This clock implementation does not account for power loss; if the Arduino resets, the time will need to be re-entered.

## Author

This code is designed by Prince Kushwaha from COSM Electronics.

Enjoy your Arduino clock project!
