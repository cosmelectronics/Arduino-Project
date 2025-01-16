// This Code is Written by Prince Kushwaha from COSM Eletronics

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin for DS18B20 sensor
#define ONE_WIRE_BUS 2

// Create instances for OneWire and DallasTemperature
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Initialize the LCD with I2C address (usually 0x27 or 0x3F, adjust if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);

  // Start DS18B20 sensor
  sensors.begin();

  // Initialize the LCD
  lcd.init();
  lcd.backlight(); // Turn on LCD backlight

  // Display startup message on the LCD
  lcd.setCursor(0, 0);
  lcd.print("DS18B20 Temp");
  lcd.setCursor(0, 1);
  lcd.print("Reading...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Request temperature from the sensor
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0); // Get temperature in Celsius
  float temperatureF = temperatureC * 9.0 / 5.0 + 32.0; // Convert to Fahrenheit

  // Debug temperature on serial monitor
  Serial.print("Temperature (C): ");
  Serial.println(temperatureC);
  Serial.print("Temperature (F): ");
  Serial.println(temperatureF);

  // Display temperature in Celsius and Fahrenheit on the LCD
  if (temperatureC == DEVICE_DISCONNECTED_C) {
    // Handle disconnected sensor case
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    Serial.println("Error: Sensor disconnected!");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperatureC, 1); // Print Celsius with 1 decimal point
    lcd.print((char)223);       // Degree symbol
    // lcd.print(" ");
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatureF, 1); // Print Fahrenheit with 1 decimal point
    lcd.print((char)223);       // Degree symbol
    lcd.print("F");
  }

  // Wait 1 second before the next reading
  delay(1000);
}
