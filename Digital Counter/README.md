# Digital Counter Using Arduino

Welcome to the Digital Counter project using Arduino! This project is designed by Prince Kushwaha from COSM Electronics.

## Overview

The Digital Counter is an Arduino-based project that leverages a Liquid Crystal Display (LCD) and EEPROM to create a simple, yet functional counting device. The counter allows for incrementing, decrementing, and resetting the count with the help of push buttons, and retains the count even after a power cycle using EEPROM memory.

## Features

- **Increment and Decrement Count:** Use buttons to increase or decrease the count displayed on the LCD.
- **EEPROM Storage:** The current count is saved to EEPROM, ensuring it is retained even when the power is off.
- **Reset Functionality:** A reset button clears the count and sets it back to zero.
- **Visual and Audio Feedback:** The LCD provides visual feedback of the count, and a buzzer indicates when the reset button is pressed.

## Components Required

- **Arduino Board:** Any standard Arduino board (e.g., Uno, Nano).
- **Liquid Crystal Display (LCD):** 16x2 LCD with I2C interface.
- **Push Buttons:** Three push buttons for increment, decrement, and reset.
- **Buzzer:** For audio feedback on reset.
- **Connecting Wires:** For making connections between components.
- **Breadboard:** Optional, for easier prototyping.

## Pin Configuration

- **bt_up:** Connect to A0 (Increment button)
- **bt_down:** Connect to A1 (Decrement button)
- **bt_reset:** Connect to A2 (Reset button)
- **buzzer:** Connect to pin 8

## Setup Instructions

1. **Wiring:** Connect the LCD, buttons, and buzzer to the Arduino as per the pin configuration.
2. **Library Installation:** Ensure the required libraries (`Wire.h`, `LiquidCrystal_I2C.h`, `EEPROM.h`) are installed in your Arduino IDE.
3. **Upload Code:** Upload the provided Arduino code to your Arduino board.

## Usage

- **Increment Count:** Press the increment button to increase the count.
- **Decrement Count:** Press the decrement button to decrease the count.
- **Reset Count:** Press and hold the reset button to reset the count to zero, indicated by the buzzer sound.
- The current count will be displayed on the LCD and saved to EEPROM automatically.

## Notes

- The counter is designed to handle counts from 00000000 to 99999999.
- Make sure to debounce the buttons for smooth operation.
- Ensure proper power supply to the Arduino and connected components to avoid inconsistent behavior.

## License

This project is open-source and available for anyone to use and modify. Contributions and improvements are welcome!

## Acknowledgements

Special thanks to COSM Electronics for supporting and promoting this project.

For any questions or further information, feel free to reach out or check the project's repository.

## Tags

Arduino, Digital Counter, EEPROM, LCD Display, Electronics, DIY Project, COSM Electronics, Embedded Systems

---

Happy Building!
