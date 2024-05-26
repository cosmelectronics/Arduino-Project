# LED Light Modes Controller

This project is designed to control the behavior of four LEDs using a mode switch. The modes include turning all LEDs off, turning all LEDs on, flashing all LEDs, and creating a waving effect.

## Components

- **1 x Arduino Board** (e.g., Arduino Uno)
- **1 x Push Button**
- **4 x LEDs**
- **4 x Current Limiting Resistors** (220Ω recommended)
- **Connecting Wires**
- **Breadboard**

## Connections

- **Mode Switch:** Connect the mode switch to digital pin 2 on the Arduino.
- **LED1:** Connect the anode (long leg) of LED1 to digital pin 12 on the Arduino. Connect the cathode (short leg) through a 220Ω resistor to ground.
- **LED2:** Connect the anode (long leg) of LED2 to digital pin 11 on the Arduino. Connect the cathode (short leg) through a 220Ω resistor to ground.
- **LED3:** Connect the anode (long leg) of LED3 to digital pin 10 on the Arduino. Connect the cathode (short leg) through a 220Ω resistor to ground.
- **LED4:** Connect the anode (long leg) of LED4 to digital pin 9 on the Arduino. Connect the cathode (short leg) through a 220Ω resistor to ground.
- **Push Button:** Connect one side of the push button to 5V and the other side to digital pin 2. Use a pull-down resistor (10kΩ) to connect the pin side of the button to ground.

## Functionality

- **Mode 0:** All LEDs are turned off.
- **Mode 1:** All LEDs are turned on.
- **Mode 2:** All LEDs flash on and off together.
- **Mode 3:** LEDs turn on and off in a sequence creating a wave effect.

## Usage

1. **Setup:** Connect all components as per the connection details provided.
2. **Upload Code:** Upload the provided code to your Arduino board using the Arduino IDE.
3. **Operation:** Press the mode switch to cycle through the different LED modes.

## Author

- Designed by Prince Kushwaha

## Tags

#arduino #ledcontrol #modeswitch #electronics #embeddedsystems #diy #maker #stem #opensource #arduinoled #ledproject #arduinoproject #arduinohacks #arduinotutorial #tech #hardware #innovation #microcontroller #programming #circuit #ledpatterns #leddisplay #coding #technology #project
