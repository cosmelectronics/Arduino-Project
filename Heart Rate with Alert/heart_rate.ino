// This Code is Designed by Prince Kushwaha from COSM Electronicsl 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define the LCD address and dimensions
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change the address to 0x3F if 0x27 doesn't work

// Define pins for the components
const int pulsePin = A0;   // Pulse rate sensor connected to analog pin A0
const int buzzerPin = 9;   // Buzzer connected to digital pin 9
const int ledPin = 8;      // LED connected to digital pin 8

// Define threshold values for the heart rate danger zone
const int lowerThreshold = 60;  // Lower threshold for heart rate (BPM)
const int upperThreshold = 100; // Upper threshold for heart rate (BPM)

void setup() {
  // Initialize the serial communication for debugging
  Serial.begin(9600);
  
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  
  // Set the buzzer and LED pins as output
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Ensure the buzzer and LED are off at the start
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Read the value from the pulse sensor
  int pulseValue = analogRead(pulsePin);

  // Convert the analog value to BPM (this conversion may need calibration)
  int heartRate = map(pulseValue, 0, 1023, 30, 180);

  // Print the heart rate to the serial monitor for debugging
  Serial.print("Heart Rate: ");
  Serial.println(heartRate);

  // Display the heart rate on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Heart Rate:");
  lcd.setCursor(0, 1);
  lcd.print(heartRate);
  lcd.print(" BPM");

  // Check if the heart rate is in the danger zone
  if (heartRate < lowerThreshold || heartRate > upperThreshold) {
    // If in danger zone, turn on the buzzer and LED
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    // If not in danger zone, turn off the buzzer and LED
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  // Delay for a short period before taking the next reading
  delay(1000);  // 1 second delay
}
