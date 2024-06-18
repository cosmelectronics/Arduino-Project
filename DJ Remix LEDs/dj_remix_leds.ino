// This Code is Designed by Prince Kushwaha from COSM Electronics

// Define the pins for the LEDs
const int redLedPin = 2;
const int greenLedPin = 3;
const int blueLedPin = 4;
const int yellowLedPin = 5;

void setup() {
  // Initialize the LED pins as outputs
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
}

void loop() {
  // Light up the LEDs in a DJ remix style
  remixLeds();
}

void remixLeds() {
  // Define the remix pattern
  int pattern[][4] = {
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1},
    {1, 1, 1, 0},
    {0, 1, 1, 1},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1},
  };
  
  int patternLength = sizeof(pattern) / sizeof(pattern[0]);

  // Loop through the pattern
  for (int i = 0; i < patternLength; i++) {
    digitalWrite(redLedPin, pattern[i][0]);
    digitalWrite(greenLedPin, pattern[i][1]);
    digitalWrite(blueLedPin, pattern[i][2]);
    digitalWrite(yellowLedPin, pattern[i][3]);
    delay(200); // Adjust the delay to change the speed of the pattern
  }
}
