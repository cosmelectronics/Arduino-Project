// This Code is Designed by Prince Kushwaha from COSM Electronics

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD. Change the address to 0x27 or 0x3F depending on your LCD's I2C address
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int analogPin = A0; // Pin where the voltage is read
float voltage = 0.0;
float referenceVoltage = 5.0; // Reference voltage of the Arduino (5V for most boards)
float scalingFactor = 2.4; // Adjust this based on your voltage divider ratio (12V / 5V)

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  
  // Print initial messages
  lcd.setCursor(0, 0);
  lcd.print("Voltage:");
}

void loop() {
  // Read the analog value (10-bit ADC, value between 0 and 1023)
  int analogValue = analogRead(analogPin);

  // Calculate the voltage
  voltage = (analogValue / 1023.0) * referenceVoltage * scalingFactor;

  // Print the voltage to the LCD
  lcd.setCursor(0, 1);
  lcd.print(voltage, 2); // Print voltage with 2 decimal places
  lcd.print(" V   "); // Clear remaining characters

  delay(500); // Update every 500 milliseconds
}
