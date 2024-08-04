# Big Height Character on 16x2 LCD

This project is a simple countdown timer that displays large digits on an LCD screen using the LiquidCrystal_I2C library. Designed by Prince Kushwaha from COSM Electronics, the code demonstrates how to create custom characters and display them in a larger format than usual on a 16x2 LCD.

## Features

- **Custom Characters**: Five custom glyphs are used to create large digits.
- **Countdown Timer**: Displays a countdown from 9 to 0 at startup.
- **Elapsed Time Display**: Continuously displays the number of seconds elapsed since the Arduino started.

## Components

- **Arduino Board**: Any compatible Arduino board.
- **16x2 I2C LCD**: A 16x2 LCD screen with an I2C interface.

## Setup

1. **Wiring**: Connect the LCD to the Arduino using the I2C interface. The I2C address for the LCD is set to `0x27` by default.

2. **Library**: Ensure you have the `LiquidCrystal_I2C` library installed in your Arduino IDE. You can install it via the Library Manager.

## How to Use

1. **Upload the Code**: Copy the provided code into your Arduino IDE and upload it to your Arduino board.
2. **Power On**: Once powered, the LCD will show a countdown from 9 to 0.
3. **Elapsed Time**: After the countdown, the LCD will display the number of seconds elapsed since the Arduino started.

## Custom Glyphs

The project uses five custom glyphs to create the segments for the large digits. These glyphs are defined in the `glyphs` array and are created during the `setup` function using `lcd.createChar`.

## Functions

- `setup()`: Initializes the LCD and shows the countdown timer.
- `loop()`: Continuously updates the display with the number of seconds elapsed.
- `showDigit(int digit, int position)`: Displays a single large digit at the specified position.
- `showNumber(int value, int position)`: Converts a number to a string and displays it using large digits.

## License

This project is open-source and available for modification and redistribution. Please credit Prince Kushwaha and COSM Electronics if you use or modify this code.

## Contact

For any inquiries or support, please contact Prince Kushwaha at COSM Electronics.
