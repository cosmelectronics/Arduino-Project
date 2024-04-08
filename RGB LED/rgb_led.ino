// This code is created by Prince Kushwaha
// Define the pins for Red, Green, and Blue LEDs
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  // Set the pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void setColor(int redValue, int greenValue, int blueValue) {
  // Set the brightness of each color pin
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void loop() {
  // Turn the LED red
  setColor(255, 0, 0);
  delay(1000);
  
  // Turn the LED green
  setColor(0, 255, 0);
  delay(1000);
  
  // Turn the LED blue
  setColor(0, 0, 255);
  delay(1000);
  
  // Turn the LED purple (red + blue)
  setColor(255, 0, 255);
  delay(1000);

  // Turn the LED yellow (red + green)
  setColor(255, 255, 0);
  delay(1000);

  // Turn the LED cyan (green + blue)
  setColor(0, 255, 255);
  delay(1000);

  // Turn the LED white (red + green + blue)
  setColor(255, 255, 255);
  delay(1000);
  
  // Turn off the LED
  setColor(0, 0, 0);
  delay(1000);
}
