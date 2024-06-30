# How to Use an LDR Sensor With Arduino

This project reads the value from a Light Dependent Resistor (LDR) and displays it on a 16x2 LCD screen using an I2C module. The LCD will show the LDR value in the first row and the text "COSMELECTRONICS" in the second row.

## Components Required

- Arduino board (e.g., Uno, Mega, Nano)
- LDR (Light Dependent Resistor)
- 10k ohm resistor
- 16x2 LCD display with I2C module
- Breadboard and connecting wires

## Circuit Diagram

1. **LDR and Resistor:**
   - Connect one end of the LDR to 5V.
   - Connect the other end of the LDR to the analog input pin A0.
   - Connect one end of the 10k ohm resistor to GND.
   - Connect the other end of the 10k ohm resistor to the junction between the LDR and the analog input pin A0.

2. **16x2 LCD with I2C:**
   - Connect the VCC and GND of the I2C module to 5V and GND on the Arduino, respectively.
   - Connect the SDA pin of the I2C module to the SDA pin on the Arduino (A4 on Uno/Nano, 20 on Mega).
   - Connect the SCL pin of the I2C module to the SCL pin on the Arduino (A5 on Uno/Nano, 21 on Mega).

## Libraries Required

- `Wire.h`: For I2C communication.
- `LiquidCrystal_I2C.h`: For controlling the LCD display via I2C.

## Setup Instructions

1. **Install the Required Libraries:**
   - Open the Arduino IDE.
   - Go to `Sketch` > `Include Library` > `Manage Libraries...`.
   - Search for `LiquidCrystal I2C` and install the library by `Frank de Brabander`.

2. **Upload the Code:**
   - Open the Arduino IDE and copy the code from `LDR_LCD_I2C.ino`.
   - Connect your Arduino board to your computer.
   - Select the correct board and port from the `Tools` menu.
   - Click the `Upload` button.

## How It Works

- The code reads the analog value from the LDR connected to pin A0.
- This value is then printed to the serial monitor for debugging purposes.
- The same value is displayed on the first row of the 16x2 LCD.
- The second row of the LCD displays the text "COSMELECTRONICS".

## Acknowledgements

- This code is designed by Prince Kushwaha.
