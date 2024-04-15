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
