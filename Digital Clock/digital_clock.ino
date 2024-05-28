// This Code is Designed by Prince Kushwaha from COSM Electronics

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change 0x27 to your I2C address

unsigned long previousMillis = 0;
const long interval = 1000;

int hours = 0;
int minutes = 0;
int seconds = 0;
bool isPM = false;

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Enter time:");
  lcd.setCursor(0, 1);
  lcd.print("HH:MM:SS AM/PM");

  // Initialize serial communication
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB
  }

  // Wait for user to input time
  String inputTime = "";
  while (inputTime.length() < 11) {
    if (Serial.available()) {
      char c = Serial.read();
      if (isDigit(c) || c == ':' || c == ' ' || c == 'A' || c == 'P' || c == 'M') {
        inputTime += c;
        Serial.print(c);
      }
      if (c == '\n' || c == '\r') {
        break;
      }
    }
  }
  Serial.println();

  // Parse the input time
  hours = inputTime.substring(0, 2).toInt();
  minutes = inputTime.substring(3, 5).toInt();
  seconds = inputTime.substring(6, 8).toInt();
  isPM = inputTime.substring(9, 11) == "PM";

  // Convert 12-hour format to 24-hour format
  if (isPM && hours < 12) {
    hours += 12;
  }
  if (!isPM && hours == 12) {
    hours = 0;
  }

  lcd.clear();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Increment the seconds
    seconds++;
    if (seconds >= 60) {
      seconds = 0;
      minutes++;
      if (minutes >= 60) {
        minutes = 0;
        hours++;
        if (hours >= 24) {
          hours = 0;
        }
      }
    }

    // Display time in HH:MM:SS AM/PM format
    lcd.setCursor(0, 0);
    lcd.print("Time: ");
    int displayHours = hours;
    bool displayPM = false;

    if (hours >= 12) {
      displayPM = true;
      if (hours > 12) {
        displayHours = hours - 12;
      }
    } else {
      displayPM = false;
      if (hours == 0) {
        displayHours = 12;
      }
    }

    if (displayHours < 10) lcd.print('0');
    lcd.print(displayHours);
    lcd.print(':');
    if (minutes < 10) lcd.print('0');
    lcd.print(minutes);
    lcd.print(':');
    if (seconds < 10) lcd.print('0');
    lcd.print(seconds);
    lcd.print(displayPM ? " PM" : " AM");
  }
}
