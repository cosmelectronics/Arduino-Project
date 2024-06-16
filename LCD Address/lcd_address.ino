// This Code is Designed by Prince Kushwaha

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Variable to hold the found address
int lcdAddress = 0;

// Function to scan I2C devices and find the LCD address
void findI2CAddress() {
  for (int address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      lcdAddress = address;
      break;
    }
  }
}

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // Scan for I2C devices
  Serial.println("Scanning...");
  findI2CAddress();

  if (lcdAddress) {
    Serial.print("I2C device found at address 0x");
    Serial.println(lcdAddress, HEX);
  } else {
    Serial.println("No I2C devices found");
  }

  // Initialize the LCD with the found address
  LiquidCrystal_I2C lcd(lcdAddress, 16, 2);
  lcd.init();
  lcd.backlight();

  // Display the address on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Scanning....");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Address is: 0x");
  lcd.print(lcdAddress, HEX);
}

void loop() {
  
}
