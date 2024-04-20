//This code is designed by Prince Kushwaha

//include the servo library
#include <Servo.h>

// Create a servo object
Servo servoMotor;

// Define the pin for the servo
const int servoPin = 9;

void setup() {
  // Attach the servo to the pin
  servoMotor.attach(servoPin);
}

void loop() {
  // Rotate the servo to 0 degrees
  servoMotor.write(0);
  delay(1000); // Wait for 1 second

  // Rotate the servo to 45 degrees
  servoMotor.write(45);
  delay(1000); // Wait for 1 second

  // Rotate the servo to 90 degrees
  servoMotor.write(90);
  delay(1000); // Wait for 1 second

  // Rotate the servo to 135 degrees
  servoMotor.write(135);
  delay(1000); // Wait for 1 second

  // Rotate the servo to 180 degrees
  servoMotor.write(180);
  delay(1000); // Wait for 1 second
}
