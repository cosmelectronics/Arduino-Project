# Arduino Relay Module Control

This project demonstrates how to interface a two-channel relay module with an Arduino to control two LEDs. The LEDs will be toggled on and off to show the relay functions.

## Components Needed
- Arduino (e.g., Uno, Nano)
- Two-channel Relay Module
- Jumper Wires
- Two LEDs (Red and Green)
- Breadboard
- Resistors (220 ohms recommended)

## Wiring Diagram

### Relay Module to Arduino
- **VCC** of the relay module to **5V** on the Arduino
- **GND** of the relay module to **GND** on the Arduino
- **IN1** of the relay module to digital pin **7** on the Arduino
- **IN2** of the relay module to digital pin **8** on the Arduino

### Relay to LEDs
- **Relay 1 (IN1)**
  - **COM** terminal to the cathode (short leg) of the Red LED
  - **NO** terminal to **GND**
  - **Anode** (long leg) of the Red LED to a current limiting resistor (220 ohms recommended)
  - Resistor to **5V**

- **Relay 2 (IN2)**
  - **COM** terminal to the cathode (short leg) of the Green LED
  - **NO** terminal to **GND**
  - **Anode** (long leg) of the Green LED to a current limiting resistor (220 ohms recommended)
  - Resistor to **5V**

## How It Works
1. **Initialization**: The relay pins are set as outputs in the `setup` function and start in the LOW state (off).
2. **Loop Function**: The `loop` function toggles the relays:
   - Turns the first relay on and the second relay off, then waits for one second.
   - Turns the first relay off and the second relay on, then waits for one second.
3. **LED Indication**: The LEDs connected to the relay's NO and COM terminals will show the relay state. When the relay is activated, the LED will light up.

## Safety Precautions
- **Low Voltage**: This example uses low voltage (5V) LEDs. If using higher voltage devices, ensure proper insulation and safety measures.
- **Circuit Disconnection**: Always disconnect the power while setting up the circuit to avoid any electrical hazards.

## Author
This code is designed by Prince Kushwaha from COSM Electronics.
