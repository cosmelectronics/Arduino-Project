// This Code is Designed by Prince Kushwaha from COSM Electronics

// Pin assignments for RGB LED
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Pin assignments for potentiometers (optional)
const int redPot = A0;
const int greenPot = A1;
const int bluePot = A2;

void setup() {
  // Set the RGB LED pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the potentiometer values (0-1023)
  int redValue = analogRead(redPot);
  int greenValue = analogRead(greenPot);
  int blueValue = analogRead(bluePot);

  // Map the potentiometer values to PWM range (0-255)
  redValue = map(redValue, 0, 1023, 255, 0); // Invert the value
  greenValue = map(greenValue, 0, 1023, 255, 0); // Invert the value
  blueValue = map(blueValue, 0, 1023, 255, 0); // Invert the value

  // Output the PWM values to the RGB LED
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  // Print the values for debugging
  Serial.print("Red: ");
  Serial.print(redValue);
  Serial.print(" Green: ");
  Serial.print(greenValue);
  Serial.print(" Blue: ");
  Serial.println(blueValue);

  // Small delay to allow for stable readings
  delay(10);
}
