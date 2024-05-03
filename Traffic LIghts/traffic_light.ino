// This Code is Designed by Prince Kushwaha
// Define LED pins
const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;

// Define timing constants (in milliseconds)
const int redDuration = 5000;    // 5 seconds for red
const int yellowDuration = 2000; // 2 seconds for yellow
const int greenDuration = 5000;  // 5 seconds for green

void setup() {
  // Initialize LED pins as outputs
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // Red light
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  delay(redDuration);

  // Yellow light
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  delay(yellowDuration);

  // Green light
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(greenDuration);
}
