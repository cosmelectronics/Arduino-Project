// This code is designed by Prince Kushwaha from COSM Electronics

const int buttonPin = 7;   // Push button pin
const int buzzerPin = 8;   // Buzzer pin
const int redLedPin = 9;   // Red LED pin
const int greenLedPin = 10; // Green LED pin

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) { // Button is pressed
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    digitalWrite(greenLedPin, HIGH); // Turn on the green LED
    digitalWrite(redLedPin, LOW); // Turn off the red LED
  } else { // Button is not pressed
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    digitalWrite(greenLedPin, LOW); // Turn off the green LED
    digitalWrite(redLedPin, HIGH); // Turn on the red LED
  }
}
