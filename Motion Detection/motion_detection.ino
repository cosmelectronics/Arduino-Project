// This Code is Designed by Prince Kushwaha from COSM Electronics

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIR_SENSOR_PIN 2  // PIR Sensor output pin

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 to 0x3F if needed

void setup() {
    pinMode(PIR_SENSOR_PIN, INPUT);
    lcd.init();
    lcd.backlight();  
    lcd.setCursor(0, 0);
    lcd.print("  PIR Sensor   ");
    lcd.setCursor(0, 1);
    lcd.print("   Ready...    ");
    delay(2000); // Wait for sensor stabilization
    lcd.clear();
}

void loop() {
    int pirState = digitalRead(PIR_SENSOR_PIN);

    lcd.setCursor(0, 0);
    lcd.print("Human Presence:");

    lcd.setCursor(0, 1);
    if (pirState == HIGH) {
        lcd.print("  Detected!    ");
    } else {
        lcd.print("  Not Detected ");
    }

    delay(500); // Small delay to prevent flickering
}
