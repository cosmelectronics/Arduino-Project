# Arduino Resistor Measurement

This project measures the resistance of an unknown resistor using an Arduino Uno, a voltage divider, and displays the result on a 16x2 I2C LCD. The project uses the analog input to read the voltage drop across the unknown resistor and calculates its resistance.

## Components

- Arduino Uno
- I2C 16x2 LCD
- Known resistor (R1) - 1000 ohms (1k ohm)
- Unknown resistor (R2)
- Breadboard
- Jumper wires

## Circuit Diagram

### Connections:

1. **I2C LCD to Arduino**:
   - VCC to 5V
   - GND to GND
   - SDA to A4
   - SCL to A5

2. **Voltage Divider**:
   - Connect the known resistor (R1) between 5V and the analog input pin (A0).
   - Connect the unknown resistor (R2) between the analog input pin (A0) and GND.

### Schematic

       +5V
        |
       [R1]  Known Resistor
        |
       A0 (Analog Pin)
        |
       [R2]  Unknown Resistor
        |
       GND

## Installation

1. **Clone the Repository**

   git clone https://github.com/yourusername/arduino-resistor-measurement.git
   cd arduino-resistor-measurement


2. **Upload the Code**:
   - Open the `.ino` file in the Arduino IDE.
   - Connect your Arduino Uno to your computer.
   - Select the correct board and port from the `Tools` menu.
   - Click on the `Upload` button to upload the code to your Arduino.

## How It Works

1. The Arduino reads the analog voltage from pin A0, which is the voltage drop across the unknown resistor (R2).
2. Using the known resistor value (R1) and the measured voltage, the Arduino calculates the resistance of R2 using the voltage divider formula.
3. The calculated resistance value is displayed on the 16x2 I2C LCD.

## Libraries Required

- **Wire**: For I2C communication.
- **LiquidCrystal_I2C**: For controlling the I2C LCD.

## Usage

Once the code is uploaded to the Arduino and the circuit is assembled:
- The LCD will display the voltage (Vout) and the resistance (R2) in ohms.
- The values will be updated every second.

## Author

This code is designed by Prince Kushwaha.
