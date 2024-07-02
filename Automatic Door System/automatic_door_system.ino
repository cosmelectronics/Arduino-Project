// This Code is Designed by Prince Kushwaha from COSM Electronics

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Pin definitions
const int trigPin = 9;
const int echoPin = 10;
const int redLEDPin = 4;
const int greenLEDPin = 5;
const int servoPin = 3;

// Constants
const int distanceThreshold = 30; // Threshold distance in cm
const int openPosition = 90; // Servo open position
const int closePosition = 0; // Servo close position
const unsigned long openDuration = 5000; // Door open duration in milliseconds

// Objects
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD address and size
Servo myServo;

// Variables
bool doorOpen = false;
unsigned long doorOpenTime = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Initialize pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);

  // Initialize servo
  myServo.attach(servoPin);
  myServo.write(closePosition); // Start with door closed

  // Initialize LEDs
  digitalWrite(redLEDPin, HIGH); // Red LED on
  digitalWrite(greenLEDPin, LOW); // Green LED off
}

void loop() {
  // Measure distance
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Convert to cm

  // Check distance and control door
  if (distance < distanceThreshold) {
    if (!doorOpen) {
      // Open door
      myServo.write(openPosition);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(greenLEDPin, HIGH);
      doorOpen = true;
      doorOpenTime = millis(); // Record the time the door was opened
    }
  } else {
    if (doorOpen && millis() - doorOpenTime >= openDuration) {
      // Close door after 5 seconds
      myServo.write(closePosition);
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(greenLEDPin, LOW);
      doorOpen = false;
    }
  }

  // Display status on LCD
  lcd.clear();
  if (doorOpen) {
    unsigned long remainingTime = (openDuration - (millis() - doorOpenTime)) / 1000;
    lcd.setCursor(0, 0);
    lcd.print("Door : OPEN");
    lcd.setCursor(0, 1);
    lcd.print("Closing in: ");
    lcd.print(remainingTime);
    lcd.print(" sec");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Door : CLOSED");
    lcd.setCursor(0, 1);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print(" cm");
  }

  // Delay before next measurement
  delay(1000);
}
