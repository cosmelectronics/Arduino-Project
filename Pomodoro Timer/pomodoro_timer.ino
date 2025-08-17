// Arduino Pomodoro Timer Project
// Description:
// 
// Arduino Pomodoro Timer
// 
// Project Overview
// This simple project uses an Arduino UNO to create a Pomodoro Timer with LED indicators and a buzzer. It helps users focus by timing 25-minute work sessions and 5-minute breaks. A button is used to start the timer.
// 
// Features
// - 25-minute work session
// - 5-minute break
// - Buzzer alerts at transitions
// - LED color changes for work/break
// 
// Components Required
// - Arduino UNO
// - Red LED
// - Green LED
// - Buzzer
// - Push Button
// - 220Ω Resistors
// - Breadboard and Jumper Wires
// 
// Circuit Connections
// Component       Arduino UNO Pin
// Red LED         D3 (via 220Ω resistor)
// Green LED       D4 (via 220Ω resistor)
// Buzzer          D5
// Push Button     D2 (with pull-down resistor)
// 


const int redLED = 3;
const int greenLED = 4;
const int buzzer = 5;
const int button = 2;

bool running = false;
unsigned long startTime = 0;
const unsigned long workTime = 25UL * 60 * 1000; // 25 minutes
const unsigned long breakTime = 5UL * 60 * 1000; // 5 minutes

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(button) == HIGH && !running) {
    running = true;
    startTime = millis();
    digitalWrite(redLED, HIGH);
    Serial.println("Work started");
    tone(buzzer, 1000, 500);
    delay(500);
  }

  if (running) {
    unsigned long elapsed = millis() - startTime;

    if (elapsed >= workTime && elapsed < workTime + breakTime) {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
      Serial.println("Break started");
    }

    if (elapsed >= workTime + breakTime) {
      digitalWrite(greenLED, LOW);
      tone(buzzer, 1500, 500);
      running = false;
      Serial.println("Session complete");
    }
  }
}
