// This Code is Designed by Prince Kushwaha

// Define the pin numbers for the push button and the LED
const int buttonPin = 2;  // Assuming the push button is connected to digital pin 2
const int ledPin = 13;    // Assuming the LED is connected to digital pin 13

// Define variables to hold the state of the button and LED
int buttonState = 0;
bool ledOn = false;

void setup() {
  // Set the button pin as input
  pinMode(buttonPin, INPUT);
  // Set the LED pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState == HIGH) {
    // Toggle the LED state
    ledOn = !ledOn;

    // Set the LED state accordingly
    digitalWrite(ledPin, ledOn ? HIGH : LOW);

    // Wait until the button is released
    while (digitalRead(buttonPin) == HIGH) {
      delay(10);  // Short delay to avoid button bounce
    }
  }
}
