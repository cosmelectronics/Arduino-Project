# Arduino Voltmeter with 16x2 I2C LCD

This project is designed to create a voltmeter that measures voltages from 0V to 12V using an Arduino and a 16x2 LCD with an I2C interface. This project is designed by Prince Kushwaha from COSM Electronics.

## Components Required

- Arduino (e.g., Uno, Nano, etc.)
- 16x2 LCD with I2C interface
- Resistors: 14kΩ and 10kΩ
- Connecting wires
- Breadboard (optional)

## Circuit Diagram

### Voltage Divider Setup

1. Connect the input voltage (up to 12V) to the top of R1 (14kΩ).
2. Connect the bottom of R1 to the top of R2 (10kΩ).
3. Connect the bottom of R2 to GND.
4. Connect the junction of R1 and R2 (middle point) to the analog input pin (A0) of the Arduino.

### I2C LCD Setup

1. Connect the GND of the LCD to the GND of the Arduino.
2. Connect the VCC of the LCD to the 5V of the Arduino.
3. Connect the SDA of the LCD to the A4 of the Arduino.
4. Connect the SCL of the LCD to the A5 of the Arduino.

### Schematic Diagram

      +12V
        |
        |
       R1 (14kΩ)
        |
        |------------------- A0 (Arduino)
        |
       R2 (10kΩ)
        |
       GND

## Software

1. Install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).
2. Install the `LiquidCrystal_I2C` library via the Library Manager in the Arduino IDE.

## How to Use

1. Wire the components as per the circuit diagram.
2. Upload the provided code to the Arduino.
3. The voltage being measured will be displayed on the 16x2 LCD.

## Adjustments

- Ensure the correct I2C address for your LCD. Common addresses are `0x27` and `0x3F`.
- If using a different reference voltage or resistor values, adjust the `scalingFactor` accordingly in the code.

## Credits

- Designed by Prince Kushwaha from COSM Electronics
