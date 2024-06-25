//This Code is Designed by Prince Kushwaha from COSM Electronics

#include <NewPing.h>
#include <NewTone.h>

// Select which PWM-capable pins are to be used.
#define RED_PIN    10
#define GREEN_PIN  11
#define BLUE_PIN   9

#define TRIGGER_PIN  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters).

#define ALARM 3

float sinVal;
int toneVal;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
boolean triggered = false; 

void setup() {
  // Set pinModes for RGB strip
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  // Reset lights
  analogWrite(RED_PIN, 0);
  analogWrite(BLUE_PIN, 0);
  analogWrite(GREEN_PIN, 0);

  // Set pinMode for alarm
  pinMode(ALARM, OUTPUT);

  // Begin serial communication for debugging
  Serial.begin(115200);

  delay(5000); // Give some time to get out of the way if needed
}

// Helper function enabling us to send a color in one command
void color(unsigned char red, unsigned char green, unsigned char blue) {
  analogWrite(RED_PIN, red);     
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

// Alarm function to flash lights and sound buzzer
void alarm() {
  Serial.println("Alarm triggered!");
  for (int x = 0; x < 180; x++) {
    // Convert degrees to radians then obtain sin value
    sinVal = (sin(x * (3.1412 / 180)));
    // Generate a frequency from the sin value
    toneVal = 2000 + (int(sinVal * 1000));
    NewTone(ALARM, toneVal);

    color(255, 0, 0); // Red
    delay(50);
    color(255, 255, 0); // Yellow
    delay(50);
  }
  noNewTone(ALARM); // Turn off the buzzer
}

void loop() {
  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  unsigned int distance = uS / US_ROUNDTRIP_CM;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance > 0 && distance < 50) { // Ignore zero values and adjust threshold distance as needed
    if (!triggered) { // Trigger the alarm only if it is not already triggered
      triggered = true;
      alarm();
    }
  } else {
    if (triggered) { // Turn off the alarm if the distance is not within the range
      triggered = false;
      // Turn off the lights and buzzer
      analogWrite(RED_PIN, 0);
      analogWrite(GREEN_PIN, 0);
      analogWrite(BLUE_PIN, 0);
      noNewTone(ALARM);
      Serial.println("Alarm reset");
    }
  }
}
