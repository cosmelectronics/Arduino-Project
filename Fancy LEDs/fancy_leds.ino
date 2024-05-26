//This code is designed by Prince Kushwaha
int switchPin = 2;   // mode switch is connected to pin 2
int led1Pin = 12; 
int led2Pin = 11;
int led3Pin = 10;
int led4Pin = 9;

int val;            // variable for reading the pin status
int val2;           // variable for reading the delayed status
int buttonState;    // variable to hold the mode switch state
int lightMode = 0;  // variable to hold the current light mode

void setup() {
  pinMode(switchPin, INPUT);   // Set the mode switch pin as input
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);

  Serial.begin(9600);          // Set up serial communication at 9600bps
  buttonState = digitalRead(switchPin);  // read the initial state
}

void loop() {
  val = digitalRead(switchPin);  // read input value and store it in val
  delay(10);                     // debounce delay
  val2 = digitalRead(switchPin); // read the input again to prevent key bounce

  if (val == val2) {             // if the readings are consistent
    if (val != buttonState) {    // if the button state has changed
      if (val == HIGH) {         // if the button is pressed
        lightMode = (lightMode + 1) % 4;  // cycle through modes 0 to 3
      }
      buttonState = val;         // save the new state in our variable
    }
  }

  // Now do whatever the lightMode indicates
  switch (lightMode) {
    case 0:  // LEDs-off
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      break;

    case 1:  // LEDs-on
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      break;

    case 2:  // LEDs-flashing
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, HIGH);
      digitalWrite(led4Pin, HIGH);
      delay(100);
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      delay(100);
      break;

    case 3:  // LEDs-waving
      digitalWrite(led1Pin, HIGH);
      delay(50);
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, HIGH);
      delay(50);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, HIGH);
      delay(50);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, HIGH);
      delay(50);
      digitalWrite(led4Pin, LOW);
      break;
  }
}
