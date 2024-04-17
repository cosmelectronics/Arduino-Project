//This code is Designed by Prince Kushwaha
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int trigPin = 5; // set the Trigger pin to D5
const int echoPin = 6; // set the Echo Pin to D6
long pingTravelTime;
int distanceInCm;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  // Initialize the LCD
  lcd.init();
  // Turn on the backlight
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTravelTime = pulseIn(echoPin, HIGH);
  distanceInCm = pingTravelTime * 0.0340 / 2;
  delay(20);
  
  // Print distance on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distanceInCm);
  lcd.print(" cm");
  
  // Print distance on Serial Monitor
  Serial.println(distanceInCm);
  
  delay(1000);
}
