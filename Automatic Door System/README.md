# Automatic Door Opening and Closing System

This project is an automatic door opening and closing system using an Arduino UNO, an ultrasonic sensor, red and green LEDs, a 16x2 LCD with I2C, and a servo motor. The door opens when a person is detected within a threshold distance and closes automatically after 5 seconds.

## Features

- **Automatic Door Control**: The door opens when a person is detected within a specified distance and closes automatically after a set duration.
- **Distance Measurement**: Uses an ultrasonic sensor to measure the distance and detect the presence of a person.
- **Status Indicators**: Red and green LEDs indicate the door status (closed/open).
- **LCD Display**: A 16x2 LCD shows the door status and the remaining time before the door closes.
- **Adjustable Parameters**: Threshold distance and open duration can be adjusted in the code.

## Components Required

- Arduino UNO
- Ultrasonic sensor (HC-SR04)
- Servo motor
- Red and green LEDs
- 16x2 LCD with I2C module
- Connecting wires
- Breadboard
- Resistors (220Ω)

## Connections

### Ultrasonic Sensor

- **VCC** -> 5V
- **GND** -> GND
- **Trig** -> Digital Pin 9
- **Echo** -> Digital Pin 10

### Servo Motor

- **VCC** -> 5V
- **GND** -> GND
- **Signal** -> Digital Pin 3

### Red LED

- **Anode** -> Digital Pin 4
- **Cathode** -> GND (through a 220Ω resistor)

### Green LED

- **Anode** -> Digital Pin 5
- **Cathode** -> GND (through a 220Ω resistor)

### 16x2 LCD with I2C

- **SDA** -> A4
- **SCL** -> A5
- **VCC** -> 5V
- **GND** -> GND

## Usage

1. Connect the components as described in the "Connections" section.
2. Upload the provided code to the Arduino UNO using the Arduino IDE.
3. Power on the system.
4. The LCD will display the door status and the distance measured by the ultrasonic sensor. The door will open when a person is detected within the threshold distance and will close automatically after 5 seconds.

## Acknowledgements

This Code is Designed by Prince Kushwaha from COSM Electronics.
