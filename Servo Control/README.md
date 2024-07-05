# Servo Motor Control with Potentiometer

This project demonstrates how to control a servo motor using a potentiometer. The servo motor's position is adjusted based on the potentiometer's analog input. The code reads the potentiometer value, maps it to the servo's range, and updates the servo position accordingly.

## Components Required

- Arduino board
- Servo motor
- Potentiometer
- Connecting wires

## Circuit Diagram

- Mentioned in the File.

## How It Works

1. **Setup:**
   - The servo motor is attached to a specified pin on the Arduino board.
   - The potentiometer is connected to an analog input pin.

2. **Loop:**
   - The analog value from the potentiometer is read.
   - This value is mapped from its original range (0-1023) to the servo's range (0-180 degrees).
   - The servo position is updated based on the mapped value.
   - A small delay is added for stability.

## Steps to Run the Project

1. **Connect the Components:**
   - Connect the servo motor's control wire to pin 3 on the Arduino.
   - Connect the potentiometer's middle pin to analog input A0 on the Arduino.
   - Connect the other pins of the potentiometer to 5V and GND.

2. **Upload the Code:**
   - Open the Arduino IDE.
   - Copy and paste the provided code into the IDE.
   - Upload the code to the Arduino board.

3. **Test the Setup:**
   - Turn the potentiometer knob and observe the servo motor's position changing accordingly.

## Additional Information

- This code is designed by Prince Kushwaha from COSM Electronics.
- For detailed explanation and troubleshooting, refer to the official documentation of the Servo library.
