# Push Button Control with Buzzer and LEDs

This Arduino project demonstrates how to control a buzzer and two LEDs (red and green) using a push button. When the button is pressed, the buzzer sounds and the green LED lights up. When the button is released, the buzzer stops and the red LED lights up.

## Components Needed:
- Arduino board (e.g., Arduino Uno)
- Push button
- Buzzer
- Red LED
- Green LED
- 10k ohm resistor (optional)

## Connections:
1. Connect one leg of the push button to digital pin 7 on the Arduino.
2. Connect the other leg of the push button to ground (GND) on the Arduino.
3. Optionally, connect a 10k ohm resistor between the pin connected to the push button (pin 7) and the ground to avoid floating input when the button is not pressed.
4. Connect the buzzer's positive (anode) pin to digital pin 8 on the Arduino.
5. Connect the buzzer's negative (cathode) pin to ground (GND) on the Arduino.
6. Connect the positive leg of the red LED to digital pin 9 on the Arduino.
7. Connect the negative leg of the red LED to ground (GND) on the Arduino.
8. Connect the positive leg of the green LED to digital pin 10 on the Arduino.
9. Connect the negative leg of the green LED to ground (GND) on the Arduino.

**Note:** Ensure to modify the connections and pin numbers if you deviate from the specified configuration.

## Author:
This code is designed by Prince Kushwaha from COSM Electronics.

Feel free to modify and experiment with the code according to your needs!
