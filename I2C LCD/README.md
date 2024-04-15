```markdown
# I2C LCD Screen Project

This project aims to provide a simple guide for programming I2C LCD screens using the LiquidCrystal_I2C library with Arduino. It's designed for individuals who are looking for straightforward instructions on setting up and coding these displays.

## Requirements
- Arduino board
- I2C LCD screen
- LiquidCrystal_I2C library
- Wire library

## Setup
1. **Library Installation**: Download the LiquidCrystal_I2C and Wire libraries.
- Search for the LiquidCrystal_I2C and Wire.h in Arduino IDE libraries sections.

2. **Hardware Connections**:
   Connect the I2C LCD screen to the Arduino board as follows:
   - GND -> Ground
   - VCC -> +5V
   - SDA -> A4
   - SCL -> A5

## Code
```cpp
// Code authored by Prince Kushwaha

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Initialize the LiquidCrystal library:
// - The first parameter is the I2C address
// - The second parameter is how many rows are on your screen
// - The third parameter is how many columns are on your screen
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the LCD screen
  lcd.init();
  // Turn on the backlight
  lcd.backlight();
}

void loop() {
  // Wait for a second
  delay(1000);
  // Tell the screen to write on the top row
  lcd.setCursor(0, 0);
  // Tell the screen to write "Hello, from" on the top row
  lcd.print("Hello, from");
  // Tell the screen to write on the bottom row
  lcd.setCursor(0, 1);
  // Tell the screen to write "COSM Electronics" on the bottom row
  // You can change what's in the quotes to be what you want it to be!
  lcd.print("COSM Electronics");
}
```
**Note**: Ensure to clear any existing sketch before pasting the provided code.

## Credits
- Project by Prince Kushwaha
