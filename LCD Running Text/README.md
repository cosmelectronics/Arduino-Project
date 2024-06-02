# Scrolling Text on I2C LCD

This project demonstrates how to display and scroll text on an LCD screen using the I2C interface with an Arduino. The example scrolls the text "Hello!! from COSM Electronics... Subscribe My Channel" across a 16x2 I2C LCD.

## Materials Required

- Arduino board (e.g., Arduino Uno)
- 16x2 I2C LCD
- Jumper wires
- Breadboard (optional)

## Circuit Diagram

| I2C LCD Pin | Arduino Pin   |
|-------------|---------------|
| VCC         | 5V            |
| GND         | GND           |
| SDA         | A4 (on Uno)   |
| SCL         | A5 (on Uno)   |

## Installation

1. **Connect the Hardware:**
   - Connect the I2C LCD to the Arduino as per the circuit diagram above.

2. **Install Required Libraries:**
   - Open the Arduino IDE.
   - Go to **Sketch** > **Include Library** > **Manage Libraries...**
   - Search for `LiquidCrystal_I2C` and install the library by Frank de Brabander.

3. **Upload the Code:**
   - Copy the provided code into the Arduino IDE.
   - Select the correct board and port from the **Tools** menu.
   - Upload the code to your Arduino.

## Usage

Once the code is uploaded, you should see the text "Hello!! from COSM Electronics... Subscribe My Channel" scrolling across the LCD screen.

## Customization

- **Adjust the I2C Address:**
  - The I2C address is set to `0x27` by default. If your LCD uses a different address, modify the address in the code: `LiquidCrystal_I2C lcd(0x27, 16, 2);`

- **Change Display Dimensions:**
  - If you are using a different sized LCD, adjust the dimensions accordingly in the code: `LiquidCrystal_I2C lcd(0x27, 16, 2);`

- **Modify Scrolling Text:**
  - Change the content of the `scrollText` variable to display your custom message.

- **Adjust Scrolling Speed:**
  - Modify the delay in the loop to speed up or slow down the scrolling: `delay(300);`

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any bugs or feature requests.

## Acknowledgments

- This project uses the `LiquidCrystal_I2C` library by Frank de Brabander.

## Contact

For any questions or inquiries, please contact [cosmelectronics@gmail.com].

---

**Note:** Make sure to subscribe to [COSM Electronics](www.youtube.com/@cosmelectronics) for more tutorials and projects!
