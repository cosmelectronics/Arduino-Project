# Arduino I2C LCD Address Finder

This project is designed to find the I2C address of a 16x2 LCD connected to an Arduino Uno and display the found address on the LCD itself.

## Components Needed

- Arduino Uno
- 16x2 LCD with I2C module
- Jumper wires
- Breadboard (optional)

## Wiring

Connect the I2C module to the Arduino Uno as follows:

- **GND**: Connect to GND on the Arduino
- **VCC**: Connect to 5V on the Arduino
- **SDA**: Connect to A4 on the Arduino
- **SCL**: Connect to A5 on the Arduino

## Installation

1. Open the Arduino IDE.
2. Go to **Sketch > Include Library > Manage Libraries**.
3. Search for "LiquidCrystal I2C" and install the library by Frank de Brabander.

## Usage

1. Clone or download this repository.
2. Open the `I2C_LCD_Address_Finder.ino` file in the Arduino IDE.
3. Connect your Arduino Uno to your computer.
4. Upload the code to the Arduino.
5. Open the Serial Monitor (set to 9600 baud rate) to see the scanning process.
6. The LCD will display the found address. If no address is found, the LCD will not update with an address.

## Notes

- Ensure all connections are secure and correct.
- Adjust the contrast using the potentiometer on the I2C module if needed.

## Author

This code is designed by Prince Kushwaha.
