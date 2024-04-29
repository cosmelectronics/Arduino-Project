// This Code is designed by Prince Kushwaha

// Define the pin numbers for the push button and the LED
const int buttonPin = 2; // Assuming the push button is connected to digital pin 2
const int ledPin = 9;    // Assuming the LED is connected to PWM pin 9

// Define variables to hold the state of the button and the brightness of the LED
int buttonState = 0;
int brightness = 0;      // Initial brightness level

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
    // Increase brightness level
    brightness += 25;
    
    // Ensure brightness stays within valid range (0 to 255)
    if (brightness > 255) {
      brightness = 0; // Reset brightness to zero
    }

    // Update LED brightness
    analogWrite(ledPin, brightness);

    // Wait for button release
    while (digitalRead(buttonPin) == HIGH) {
      delay(10); // Short delay to debounce the button
    }
  }
}
