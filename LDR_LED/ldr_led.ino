//This Code is designed by Prince Kushwaha

// Define the LDR pin
#define LDRpin A0
int LDRValue = 0;
int LedPin = 13;  // Pin for the LED

void setup() {
  // Begin serial communication
  Serial.begin(9600);

  // Set LED pin as output
  pinMode(LedPin, OUTPUT);

  // Turn off the LED initially
  digitalWrite(LedPin, LOW);
}

void loop() {
  // Read the value from the LDR
  LDRValue = analogRead(LDRpin);

  // Print the LDR value
  Serial.println(LDRValue);
  delay(2);

  // If LDR value is greater than 300, turn off the LED
  if (LDRValue > 25) {
    digitalWrite(LedPin, LOW);
  }
  // Otherwise, turn on the LED
  else {
    digitalWrite(LedPin, HIGH);
  }
}
