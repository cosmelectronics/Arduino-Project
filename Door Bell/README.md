# Arduino Doorbell Project

This Arduino project creates a doorbell that plays a melody when a push button is pressed. The project uses a buzzer to generate sound and a push button to trigger the melody.

## Components

- Arduino board
- Push button
- Buzzer
- BC547 transistor
- Resistors (if needed)
- Connecting wires
- Breadboard

## Circuit Diagram

Connect the components as follows:

### Push Button

- Connect one leg of the push button to digital pin 12 on the Arduino.
- Connect the other leg of the push button to ground (GND) on the Arduino.
- Optionally, connect a 10k ohm resistor between the pin connected to the push button and ground to avoid floating input when the button is not pressed.

### Buzzer with BC547 Transistor

- Connect the positive terminal of the buzzer to the 5V pin on the Arduino.
- Connect the emitter pin of the BC547 transistor to ground (GND).
- Connect the base pin of the BC547 transistor to digital pin 7 on the Arduino.
- Connect the collector pin of the BC547 transistor to the negative terminal of the buzzer.

## How to Use

1. Connect the push button and buzzer (with BC547 transistor) to the specified pins on the Arduino.
2. Upload the code to your Arduino board using the Arduino IDE.
3. Press the push button to hear the doorbell melody.

## Notes

- Ensure the "pitches.h" library is available in your Arduino libraries folder. This library defines the note frequencies used in the melody.
- You can customize the melody and note durations as desired.

## Author

This code is designed by Prince Kushwaha from COSM Electronics.

## Tags

#arduino #doorbell #pushbutton #buzzer #melody #tone #digitalinput #digitaloutput #circuit #music #sound #embeddedsystems #diyelectronics #homeautomation #prototyping #microcontroller #interactiveprojects #arduinoide #breadboard #pitcheslibrary #signalprocessing #delayfunction #coding #electronicshobbyist #smarthomeproject
