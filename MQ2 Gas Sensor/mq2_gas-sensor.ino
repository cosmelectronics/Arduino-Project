// This Code is Designed by Prince Kushwaha
#include <Wire.h>  // Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h>  // Include the LiquidCrystal_I2C library

// Define the address for the LCD (you might need to change this based on your I2C module)
#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Define the analog pin connected to the MQ-2 sensor
const int mq2_analog_pin = A0;

// Initialize the LCD with the I2C address and number of columns and rows
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);

  // Initialize the LCD
  lcd.init();

  // Turn on the backlight
  lcd.backlight();
}

void loop() {
  // Read the analog value from the MQ-2 sensor
  int sensor_value = analogRead(mq2_analog_pin);

  // Convert the analog value to voltage
  float voltage = sensor_value * (5.0 / 1023.0);

  // Print the sensor value and voltage to the serial monitor
  Serial.print("Sensor Value: ");
  Serial.print(sensor_value);
  Serial.print(", Voltage: ");
  Serial.println(voltage);

  // Clear the LCD
  lcd.clear();

  // Print sensor value and voltage on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Sensor Value:");
  lcd.setCursor(0, 1);
  lcd.print(sensor_value);

  // Delay for a short period before reading again
  delay(1000);
}
