// This code is designed by Prince Kushwaha
// Include necessary libraries
#include "DHT.h"
#include <LiquidCrystal_I2C.h>

// Define pin and sensor type for DHT sensor
#define DHTPIN 4
#define DHTTYPE DHT11
// Uncomment one of the following lines based on the sensor you're using
#define DHTTYPE DHT11
//#define DHTTYPE DHT22

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Initialize LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize DHT sensor
  dht.begin();
  
  // Turn on LCD backlight
  lcd.backlight();
  
  // Initialize LCD
  lcd.init();
}

void loop() {
  // Clear LCD
  lcd.clear();
  
  // Display Humidity
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print((float)dht.readHumidity());
  lcd.print("%");
  
  // Display Temperature
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print((float)dht.readTemperature());
  lcd.print(" C");
  
  // Delay before refreshing display
  delay(2000);
  
  // Clear LCD for next readings
  lcd.clear();
}
