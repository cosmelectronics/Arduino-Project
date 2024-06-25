# Simple Arduino Alarm System

This project is designed to create an alarm system using an ultrasonic distance sensor, RGB LEDs, and a piezo buzzer. When an object comes within a specified distance, the alarm system will trigger, flashing lights and sounding the buzzer. The system is built using an Arduino and relevant libraries.

## Components

1. **Arduino**: The microcontroller used to run the code and control all components.
2. **Ultrasonic Distance Sensor (HC-SR04)**: Measures the distance to an object using sound waves.
3. **RGB LEDs**: Displays different colors based on the alarm state.
4. **Piezo Buzzer**: Produces sound to indicate an alarm state.

## Pin Definitions

- **RED_PIN**: Pin 10 - Controls the red LED.
- **GREEN_PIN**: Pin 11 - Controls the green LED.
- **BLUE_PIN**: Pin 9 - Controls the blue LED.
- **TRIGGER_PIN**: Pin 6 - Trigger pin for the ultrasonic sensor.
- **ECHO_PIN**: Pin 7 - Echo pin for the ultrasonic sensor.
- **ALARM**: Pin 3 - Controls the piezo buzzer.

## Libraries Used

1. **NewPing**: Handles the ultrasonic sensor operations.
2. **NewTone**: Handles generating tones for the piezo buzzer without conflicting with the NewPing library.

## Key Variables

- **MAX_DISTANCE**: The maximum distance the sensor will ping for, set to 100 centimeters.
- **sinVal**: Used to store sine values for generating tones.
- **toneVal**: Used to store the calculated tone frequency for the buzzer.
- **triggered**: A boolean flag to indicate whether the alarm has been triggered.

## Functions

- **setup()**: Initializes pin modes, resets LEDs, and sets up the serial communication for debugging.
- **color(red, green, blue)**: Sets the RGB LED color.
- **alarm()**: Flashes the LEDs and sounds the buzzer when the alarm is triggered.
- **loop()**: Continuously checks the distance measured by the sensor, triggers the alarm if the distance is below the threshold, and resets the alarm when the distance goes above the threshold.

## How It Works

1. **Initialization**: Sets up the RGB LEDs, buzzer, and ultrasonic sensor.
2. **Main Loop**:
   - Continuously pings the ultrasonic sensor to measure distance.
   - If the measured distance is between 0 and 50 cm, the alarm is triggered.
   - If the distance is outside this range, the alarm is reset.

## Debugging

The system uses serial communication to print the measured distance for debugging purposes. This helps in understanding the sensor readings and adjusting the threshold distance if necessary.

## Designed By

Prince Kushwaha from COSM Electronics

## Usage

1. **Setup the hardware**: Connect the components to the specified pins on the Arduino.
2. **Upload the code**: Use the Arduino IDE to upload the code to the Arduino.
3. **Power the system**: Once powered, the system will start monitoring the distance and trigger the alarm if an object is detected within the specified range.

Ensure the wiring is correct and the components are functioning as expected. Adjust the distance threshold if necessary to fit your specific use case.
