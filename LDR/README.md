# Arduino LDR Value Display on LCD

This Arduino project displays the value read from a Light Dependent Resistor (LDR) on a 16x2 LCD screen using I2C communication. It provides a simple example of how to interface an analog sensor with an LCD display for visual feedback.

## Description

The code reads the analog value from the LDR connected to pin A0 of the Arduino board. It then displays this value along with a label "LDR Value:" on the first line of the LCD screen. Additionally, it prints the LDR value to the serial monitor for debugging purposes.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno)
- 16x2 LCD display with I2C module
- Light Dependent Resistor (LDR)
- 10 kΩ resistor
- Potentiometer (optional, for adjusting contrast of LCD)

## Circuit Diagram

- Mentioned in the LDR folder.

### Connections:

#### Light Dependent Resistor (LDR) Connection:

1. Connect one end of the LDR to the 5V pin on the Arduino.
2. Connect one end of the 10 kΩ resistor to the other end of the LDR.
3. Connect the other end of the 10 kΩ resistor to the GND pin on the Arduino.
4. Connect a jumper wire from A0 to the point between the LDR and the resistor.

#### LCD with I2C Module Connection:

1. Connect the SDA pin of the I2C module to the A4 pin on the Arduino.
2. Connect the SCL pin of the I2C module to the A5 pin on the Arduino.
3. Connect the VCC pin of the I2C module to the 5V pin on the Arduino.
4. Connect the GND pin of the I2C module to the GND pin on the Arduino.

## Installation

1. Connect the components as per the circuit diagram.
2. Upload the provided Arduino sketch to your Arduino board.

## Usage

1. Once the code is uploaded, open the serial monitor to view the LDR values being read.
2. The LCD screen will display the label "LDR Value:" followed by the actual LDR value, along with a message "COSM Electronics" on the second line.

## Author

This code is designed by Prince Kushwaha.
