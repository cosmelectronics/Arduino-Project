// This code is Designed by Prince Kushwaha

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the library with the I2C address of your LCD.
// The typical address for most I2C LCDs is 0x27 or 0x3F.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize serial communication at 9600 baud.
  Serial.begin(9600);

  // Initialize the LCD.
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {
  // Read the analog values from the specified analog pins.
  int voltage_value0 = analogRead(A0);
  int voltage_value1 = analogRead(A1);

  // Calculate the subtracted value.
  int subraction_value = voltage_value0 - voltage_value1;

  // Convert the subtracted value to a voltage.
  float temp_val = subraction_value * 0.00488;

  // Calculate the current value.
  float current_value = temp_val / 22;

  // Print the current value to the Serial Monitor.
  Serial.print(current_value);

  // Display the current value on the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Current Value=");
  lcd.setCursor(0, 1);
  lcd.print(current_value);
  lcd.print("A");

  // Wait for a second before repeating the loop.
  delay(1000);
}
