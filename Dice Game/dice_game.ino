// This code is designed by Prince Kushwaha
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display
int buttonPin = 6; // Define the push button pin
int buzzerPin = 7; // Define the buzzer pin
int ledR = 9; // Define the red pin of RGB LED
int ledG = 10; // Define the green pin of RGB LED
int ledB = 8; // Define the blue pin of RGB LED
int animationDelay = 50; // Delay between animation frames

void setup() {
  lcd.init(); // Initialize the LCD
  pinMode(buttonPin, INPUT_PULLUP); // Set the push button pin as input with internal pull-up resistor
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as output
  pinMode(ledR, OUTPUT); // Set the red pin of RGB LED as output
  pinMode(ledG, OUTPUT); // Set the green pin of RGB LED as output
  pinMode(ledB, OUTPUT); // Set the blue pin of RGB LED as output
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) { // Check if the button is pressed
    digitalWrite(ledR, LOW); // Turn off red LED
    digitalWrite(ledG, LOW); // Turn off green LED
    digitalWrite(ledB, LOW); // Turn off blue LED
    for (int i = 0; i < 10; i++) { // Roll the dice rapidly
      int randomNumber = random(1, 7); // Generate a random number between 1 and 6
      displayNumber(randomNumber); // Display the current random number
      delay(animationDelay); // Animation delay
    }
    int finalNumber = random(1, 7); // Generate a random number for the final result
    displayNumber(finalNumber); // Display the final random number
    tone(buzzerPin, 1000, 200); // Play a tone on the buzzer
    randomColor(); // Generate a random color for the RGB LED
    delay(1000); // Delay for effect
    noTone(buzzerPin); // Turn off the buzzer after a short duration
    delay(2000); // Wait for 2 seconds before accepting next button press
  }
}

void displayNumber(int number) {
  lcd.clear(); // Clear the LCD
  lcd.setCursor(0, 0); // Set the cursor to the first line
  lcd.print("Dice: "); // Print label
  lcd.print(number); // Print the number
}

void randomColor() {
  analogWrite(ledR, random(0, 256)); // Set a random value for red LED
  analogWrite(ledG, random(0, 256)); // Set a random value for green LED
  analogWrite(ledB, random(0, 256)); // Set a random value for blue LED
}
