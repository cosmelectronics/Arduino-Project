// This code is designed by Prince Kushwaha
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LDRpin A0
int LDRValue = 0;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // Initialize the LCD with the I2C address and dimensions
  lcd.init();
  // Turn on the backlight
  lcd.backlight();
  // Set up serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop()
{
  // Read the value from the LDR
  LDRValue = analogRead(LDRpin);

  // Print the value on the serial monitor (optional)
  Serial.println(LDRValue);

  // Print the value on the LCD
  lcd.clear(); // Clear the LCD screen
  lcd.setCursor(0, 0); // Set cursor to the beginning of the first line
  lcd.print("LDR Value: "); // Print a label
  lcd.print(LDRValue); // Print the LDR value
  lcd.setCursor(0, 1); // Set cursor to the beginning of the second line
  lcd.print("COSM Electronics"); // Print a company name or any other message

  delay(1000); // Delay for readability (adjust as needed)
}
