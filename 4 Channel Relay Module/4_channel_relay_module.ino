// This Code is Designed by Prince Kushwaha from COSM Electronics
// Define relay pin connections as IN1 to IN4
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

void setup() {
  // Initialize the relay pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start with all relays off
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void loop() {
  // Turn each relay on for 1 second, then off for 1 second
  digitalWrite(IN1, LOW); // Turn relay IN1 on
  delay(1000);
  digitalWrite(IN1, HIGH); // Turn relay IN1 off
  delay(1000);

  digitalWrite(IN2, LOW); // Turn relay IN2 on
  delay(1000);
  digitalWrite(IN2, HIGH); // Turn relay IN2 off
  delay(1000);

  digitalWrite(IN3, LOW); // Turn relay IN3 on
  delay(1000);
  digitalWrite(IN3, HIGH); // Turn relay IN3 off
  delay(1000);

  digitalWrite(IN4, LOW); // Turn relay IN4 on
  delay(1000);
  digitalWrite(IN4, HIGH); // Turn relay IN4 off
  delay(1000);
}
