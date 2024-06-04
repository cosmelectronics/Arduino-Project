// This Code is Designed by Prince Kushwaha from COSM Electronics

// Define the pin numbers for each segment
const int segmentPins[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // Last pin is for the decimal point (dp)

// Define the segment states for digits 0-9
const byte digitPatterns[10] = {
  0b11000000, // 0
  0b11111001, // 1
  0b10100100, // 2
  0b10110000, // 3
  0b10011001, // 4
  0b10010010, // 5
  0b10000010, // 6
  0b11111000, // 7
  0b10000000, // 8
  0b10010000  // 9
};

void setup() {
  // Set all segment pins as output
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], HIGH); // Turn off all segments (common anode)
  }
}

void loop() {
  // Display digits 0-9 in a loop with a delay
  for (int digit = 0; digit < 10; digit++) {
    displayDigit(digit);
    delay(1000); // 1 second delay between digits
  }
}

// Function to display a digit on the 7-segment display
void displayDigit(int digit) {
  if (digit < 0 || digit > 9) return; // Invalid digit

  byte pattern = digitPatterns[digit];
  
  // Set each segment according to the pattern
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], (pattern & (1 << i)) ? HIGH : LOW);
  }
}
