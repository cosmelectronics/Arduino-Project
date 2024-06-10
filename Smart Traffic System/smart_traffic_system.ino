// Smart Traffic Managment System
// This Code is Designed by Prince Kushwaha from COSM Electronics

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int redLED = 2;
const int yellowLED = 3;
const int greenLED = 4;

int redTime = 10;  // Time for red LED (STOP)
int greenTime = 15;  // Time for green LED (GO)
int yellowTime = 2;  // Time for yellow LED (TRANSITION)

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  
  // Initialize the LED pins as output
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // Green LED (GO)
  digitalWrite(greenLED, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GO");
  for (int i = greenTime; i > 0; i--) {
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(i);
    lcd.print("  ");  // Clear any extra characters
    delay(1000);
  }
  digitalWrite(greenLED, LOW);

  // Yellow LED
  digitalWrite(yellowLED, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SLOW");
  for (int i = yellowTime; i > 0; i--) {
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(i);
    lcd.print("  ");  // Clear any extra characters
    delay(1000);
  }
  digitalWrite(yellowLED, LOW);

  // Red LED (STOP)
  digitalWrite(redLED, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("STOP");
  for (int i = redTime; i > 0; i--) {
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(i);
    lcd.print("  ");  // Clear any extra characters
    delay(1000);
  }
  digitalWrite(redLED, LOW);
  
  // Yellow LED before turning Green again
  digitalWrite(yellowLED, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SLOW");
  for (int i = yellowTime; i > 0; i--) {
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(i);
    lcd.print("  ");  // Clear any extra characters
    delay(1000);
  }
  digitalWrite(yellowLED, LOW);
}
