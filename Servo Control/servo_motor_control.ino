// This Code is Designed by Prince Kushwaha from COSM Electronics

#include <Servo.h>  // Include the servo library

Servo servoMotor;  // Create a servo object

int potentiometerValue;  // Variable to store the potentiometer value

void setup() {
  servoMotor.attach(3);  // Attach the servo to pin 3
}

void loop() {
  // Read the value from the potentiometer (connected to A0)
  potentiometerValue = analogRead(A0);

  // Map the potentiometer value from the range 0-1023 to the range 0-180
  potentiometerValue = map(potentiometerValue, 0, 1023, 0, 180);

  // Set the servo position according to the mapped value
  servoMotor.write(potentiometerValue);

  // Small delay for stability
  delay(20);
}
