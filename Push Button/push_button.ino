// This Code is Designed by Prince Kushwaha from COSM Electronics

int lPin = 8; // LED Pin number
int bPin = 12; //Button Pin number
int bRead; //for reading the Push Button
int dTime = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lPin, OUTPUT);
  pinMode(bPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bRead = digitalRead(bPin);
  Serial.print("Button State: ");
  Serial.println(bRead);
  delay(dTime);

  if (bRead == 1) {
    digitalWrite(lPin, HIGH);
  }
  if (bRead == 0) {
    digitalWrite(lPin, LOW);
  }
}
