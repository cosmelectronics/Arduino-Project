// Digital Counter Using Arduino| EEPROM Counter
// This Code is Designed by Prince Kushwaha from COSM Electronics

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

#define bt_up   A0
#define bt_down A1
#define bt_reset A2
#define buzzer 8

long d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, d8 = 0;
int flag1 = 0, flag2 = 0, timer = 0;

void setup() {
  pinMode(bt_up, INPUT_PULLUP);
  pinMode(bt_down, INPUT_PULLUP);
  pinMode(bt_reset, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight(); // Turn on the LCD backlight
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Welcome To  ");
  lcd.setCursor(0, 1);
  lcd.print("Digital Counter");
  delay(2000);
  lcd.clear();

  if (EEPROM.read(50) != 1) {
    WriteEeprom();
    EEPROM.write(50, 1); // Mark EEPROM as initialized
  } else {
    ReadEeprom();
  }
}

void loop() {
  if (digitalRead(bt_up) == LOW) {
    if (flag1 == 0) {
      flag1 = 1;
      d1 = d1 + 1;
      if (d1 > 9) { d1 = 0; d2 = d2 + 1; }
      if (d2 > 9) { d2 = 0; d3 = d3 + 1; }
      if (d3 > 9) { d3 = 0; d4 = d4 + 1; }
      if (d4 > 9) { d4 = 0; d5 = d5 + 1; }
      if (d5 > 9) { d5 = 0; d6 = d6 + 1; }
      if (d6 > 9) { d6 = 0; d7 = d7 + 1; }
      if (d7 > 9) { d7 = 0; d8 = d8 + 1; }
      if (d8 > 9) { d8 = 0; }
      WriteEeprom();
    }
  } else {
    flag1 = 0;
  }

  if (digitalRead(bt_down) == LOW) {
    if (flag2 == 0) {
      flag2 = 1;
      d1 = d1 - 1;
      if (d1 < 0) { d1 = 9; d2 = d2 - 1; }
      if (d2 < 0) { d2 = 9; d3 = d3 - 1; }
      if (d3 < 0) { d3 = 9; d4 = d4 - 1; }
      if (d4 < 0) { d4 = 9; d5 = d5 - 1; }
      if (d5 < 0) { d5 = 9; d6 = d6 - 1; }
      if (d6 < 0) { d6 = 9; d7 = d7 - 1; }
      if (d7 < 0) { d7 = 9; d8 = d8 - 1; }
      if (d8 < 0) { d8 = 9; }
      WriteEeprom();
    }
  } else {
    flag2 = 0;
  }

  if (digitalRead(bt_reset) == LOW) {
    digitalWrite(buzzer, HIGH);
    if (timer == 0) {
      timer = 1;
      d1 = 0; d2 = 0; d3 = 0; d4 = 0; d5 = 0; d6 = 0; d7 = 0; d8 = 0;
      WriteEeprom();
    }
  } else {
    digitalWrite(buzzer, LOW);
    timer = 0;
  }

  lcd.setCursor(0, 0);
  lcd.print("Digital Counter");
  lcd.setCursor(4, 1);
  lcd.print(d8);
  lcd.print(d7);
  lcd.print(d6);
  lcd.print(d5);
  lcd.print(d4);
  lcd.print(d3);
  lcd.print(d2);
  lcd.print(d1);
  delay(10);
}

void ReadEeprom() {
  d1 = EEPROM.read(1);
  d2 = EEPROM.read(2);
  d3 = EEPROM.read(3);
  d4 = EEPROM.read(4);
  d5 = EEPROM.read(5);
  d6 = EEPROM.read(6);
  d7 = EEPROM.read(7);
  d8 = EEPROM.read(8);
}

void WriteEeprom() {
  EEPROM.write(1, d1);
  EEPROM.write(2, d2);
  EEPROM.write(3, d3);
  EEPROM.write(4, d4);
  EEPROM.write(5, d5);
  EEPROM.write(6, d6);
  EEPROM.write(7, d7);
  EEPROM.write(8, d8);
}
