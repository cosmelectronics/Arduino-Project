// This Code is Designed by Prince Kushwaha from COSM Electronics

int seg_a = 2;
int seg_b = 3;
int seg_c = 4;
int seg_d = 5;
int seg_e = 6;
int seg_f = 7;
int seg_g = 8;
int button = 9; // Changed to a new pin for the push button
int i = 0;     // Initialize the variables

void setup() {
  // Segments a-g are the individual segments in the 7-segment display 
  pinMode(seg_a, OUTPUT); 
  pinMode(seg_b, OUTPUT);
  pinMode(seg_c, OUTPUT);
  pinMode(seg_d, OUTPUT);
  pinMode(seg_e, OUTPUT);
  pinMode(seg_f, OUTPUT);
  pinMode(seg_g, OUTPUT);
  
  pinMode(button, INPUT_PULLUP); // Set the button pin as input with pullup resistor
  
  while (digitalRead(button) == HIGH) { // Adjusted logic for the pullup resistor
    pattern(); // Function to display a pattern on the 7-segment LED
  }
  
  randomSeed(analogRead(A0)); // Read from unconnected analog pin A0
}

void loop() {
  if (digitalRead(button) == HIGH) { // If the button is pressed (adjusted for pullup resistor)
    i = random(1, 7); // Chooses a random number between 1 and 6
    for (int pat = 0; pat <= 2; pat++) {
      pattern();
    }
    sevenSeg();
    delay(200); // Debounce delay to avoid multiple readings for a single press
  }
}

void sevenSeg() {
  // Lights up the corresponding LED segments in the 7-segment LED display
  if (i == 1) {
    digitalWrite(seg_a, HIGH);
    digitalWrite(seg_b, LOW);
    digitalWrite(seg_c, LOW);
    digitalWrite(seg_d, HIGH);
    digitalWrite(seg_e, HIGH);
    digitalWrite(seg_f, HIGH);
    digitalWrite(seg_g, HIGH);
    delay(20); // Digit 1
  } else if (i == 2) {
    digitalWrite(seg_a, LOW);
    digitalWrite(seg_b, LOW);
    digitalWrite(seg_c, HIGH);
    digitalWrite(seg_d, LOW);
    digitalWrite(seg_e, LOW);
    digitalWrite(seg_f, HIGH);
    digitalWrite(seg_g, LOW);
    delay(20); // Digit 2
  } else if (i == 3) {
    digitalWrite(seg_a, LOW);
    digitalWrite(seg_b, LOW);
    digitalWrite(seg_c, LOW);
    digitalWrite(seg_d, LOW);
    digitalWrite(seg_e, HIGH);
    digitalWrite(seg_f, HIGH);
    digitalWrite(seg_g, LOW);
    delay(20); // Digit 3
  } else if (i == 4) {
    digitalWrite(seg_a, HIGH);
    digitalWrite(seg_b, LOW);
    digitalWrite(seg_c, LOW);
    digitalWrite(seg_d, HIGH);
    digitalWrite(seg_e, HIGH);
    digitalWrite(seg_f, LOW);
    digitalWrite(seg_g, LOW);
    delay(20); // Digit 4
  } else if (i == 5) {
    digitalWrite(seg_a, LOW);
    digitalWrite(seg_b, HIGH);
    digitalWrite(seg_c, LOW);
    digitalWrite(seg_d, LOW);
    digitalWrite(seg_e, HIGH);
    digitalWrite(seg_f, LOW);
    digitalWrite(seg_g, LOW);
    delay(20); // Digit 5
  } else if (i == 6) {
    digitalWrite(seg_a, LOW);
    digitalWrite(seg_b, HIGH);
    digitalWrite(seg_c, LOW);
    digitalWrite(seg_d, LOW);
    digitalWrite(seg_e, LOW);
    digitalWrite(seg_f, LOW);
    digitalWrite(seg_g, LOW);
    delay(20); // Digit 6
  }
}

void pattern() {
  // This displays a moving pattern
  digitalWrite(seg_a, LOW);
  digitalWrite(seg_b, HIGH);
  digitalWrite(seg_c, HIGH);
  digitalWrite(seg_d, HIGH);
  digitalWrite(seg_e, HIGH);
  digitalWrite(seg_f, HIGH);
  digitalWrite(seg_g, HIGH);
  delay(100);
  
  digitalWrite(seg_a, HIGH);
  digitalWrite(seg_b, LOW);
  digitalWrite(seg_c, HIGH);
  digitalWrite(seg_d, HIGH);
  digitalWrite(seg_e, HIGH);
  digitalWrite(seg_f, HIGH);
  digitalWrite(seg_g, HIGH);
  delay(100);

  digitalWrite(seg_a, HIGH);
  digitalWrite(seg_b, HIGH);
  digitalWrite(seg_c, LOW);
  digitalWrite(seg_d, HIGH);
  digitalWrite(seg_e, HIGH);
  digitalWrite(seg_f, HIGH);
  digitalWrite(seg_g, HIGH);
  delay(100);

  digitalWrite(seg_a, HIGH);
  digitalWrite(seg_b, HIGH);
  digitalWrite(seg_c, HIGH);
  digitalWrite(seg_d, LOW);
  digitalWrite(seg_e, HIGH);
  digitalWrite(seg_f, HIGH);
  digitalWrite(seg_g, HIGH);
  delay(100);

  digitalWrite(seg_a, HIGH);
  digitalWrite(seg_b, HIGH);
  digitalWrite(seg_c, HIGH);
  digitalWrite(seg_d, HIGH);
  digitalWrite(seg_e, LOW);
  digitalWrite(seg_f, HIGH);
  digitalWrite(seg_g, HIGH);
  delay(100);

  digitalWrite(seg_a, HIGH);
  digitalWrite(seg_b, HIGH);
  digitalWrite(seg_c, HIGH);
  digitalWrite(seg_d, HIGH);
  digitalWrite(seg_e, HIGH);
  digitalWrite(seg_f, LOW);
  digitalWrite(seg_g, HIGH);
  delay(100);
}
