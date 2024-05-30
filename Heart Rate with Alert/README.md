# Heart Rate Monitoring System with Alert

This project uses an Arduino to monitor heart rate using a pulse rate sensor. If the heart rate falls outside the defined safe range, an alert is triggered using a buzzer and an LED. The current heart rate is also displayed on a 16x2 LCD with an I2C module.

## Components Required

- Arduino board (e.g., Uno, Mega)
- Pulse rate sensor
- 16x2 LCD display with I2C module
- Buzzer
- LED
- 220Ω resistor (for LED)
- Connecting wires
- Breadboard (optional, for easy connections)

## Connections

### Pulse Rate Sensor

- VCC to 5V on Arduino
- GND to GND on Arduino
- Signal to A0 on Arduino

### Buzzer

- Positive leg to digital pin 9 on Arduino
- Negative leg to GND on Arduino

### LED

- Anode (longer leg) to digital pin 8 on Arduino (through a 220Ω resistor)
- Cathode (shorter leg) to GND on Arduino

### LCD with I2C Module

- SDA to A4 on Arduino (or dedicated SDA pin if available)
- SCL to A5 on Arduino (or dedicated SCL pin if available)
- VCC to 5V on Arduino
- GND to GND on Arduino

## Threshold Values

- **Lower Threshold**: 60 BPM
- **Upper Threshold**: 100 BPM

If the heart rate is below 60 BPM or above 100 BPM, the buzzer and LED will be activated to indicate a potential danger zone.

## Libraries Required

- `Wire.h` for I2C communication
- `LiquidCrystal_I2C.h` for LCD control

## Setup and Usage

1. **Install the Required Libraries**:
   - Open the Arduino IDE.
   - Go to `Sketch` > `Include Library` > `Manage Libraries`.
   - Search for `LiquidCrystal_I2C` and install it.

2. **Upload the Code**:
   - Connect your Arduino board to the computer.
   - Open the provided code in the Arduino IDE.
   - Select the correct board and port from `Tools` > `Board` and `Tools` > `Port`.
   - Click on the upload button to program the Arduino.

3. **Monitor Heart Rate**:
   - Once the code is uploaded, the heart rate will be displayed on the 16x2 LCD.
   - If the heart rate is in the danger zone, the buzzer and LED will be activated.

## Note

- The conversion from the pulse sensor's analog value to BPM might need calibration based on your specific sensor and setup.
- The I2C address for the LCD is set to `0x27` by default. If the LCD does not display anything, try changing the address to `0x3F` in the code.

## Author

This code is designed by Prince Kushwaha from COSM Electronics.
