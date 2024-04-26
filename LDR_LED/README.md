### Light Dependent Resistor (LDR) Controlled LED

This Arduino project controls an LED based on the light intensity detected by a Light Dependent Resistor (LDR).

#### Description

This project utilizes an Arduino board to read the analog value from an LDR connected to pin A0. Based on the intensity of light detected, it either turns on or off an LED connected to pin 13.

#### Prerequisites

- Arduino board
- Light Dependent Resistor (LDR)
- 10 kΩ resistor
- LED
- Jumper wires

#### Installation

1. Connect one end of the LDR to the 5V pin on the Arduino.
2. Connect one end of the 10 kΩ resistor to the other end of the LDR.
3. Connect the other end of the 10 kΩ resistor to the GND pin on the Arduino.
4. Connect a jumper wire from A0 to the point between the LDR and the resistor.
5. Connect the LED's cathode (shorter leg) to GND.
6. Connect the LED's anode (longer leg) to pin 13 on the Arduino.

#### Usage

1. Upload the provided Arduino code to your Arduino board.
2. Open the serial monitor to view the LDR readings.
3. Adjust the ambient light to observe changes in LED behavior.

#### Author

- Prince Kushwaha
