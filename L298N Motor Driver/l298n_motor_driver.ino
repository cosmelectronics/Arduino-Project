// This Code is designed by Prince Kushwaha from COSM Eletcronics 

// Motor driver pins
const int in1 = 8;  // IN1 on L298N
const int in2 = 9;  // IN2 on L298N
const int enA = 10; // ENA on L298N (PWM pin)

void setup() {
  // Set motor control pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
}

void loop() {
  // Rotate motor clockwise
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200); // Set speed (0-255)
  delay(3000); // Rotate for 3 seconds

  // Stop motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  delay(1000); // Wait 1 second

  // Rotate motor anticlockwise
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200); // Set speed
  delay(3000); // Rotate for 3 seconds

  // Stop motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  delay(1000); // Wait 1 second
}
