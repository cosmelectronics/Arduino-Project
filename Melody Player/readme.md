# Arduino Melody Player

This repository contains the code and circuit diagram for an Arduino melody player using an Arduino Uno, a BC547 transistor, a small speaker, jumper wires, and a breadboard.

## Components Used
- Arduino Uno
- BC547 Transistor
- Small Speaker
- Jumper Wires
- Breadboard

## Circuit Diagram
- Uploaded on the file

## Description
This Arduino sketch plays a melody using the components mentioned above. The melody is defined in the code using an array of note frequencies (`melody[]`) and note durations (`durations[]`). The `pitches.h` library is included to define the note frequencies.

The `setup()` function sets the `BUZZER_PIN` (Pin 7) as an output pin.

The `loop()` function iterates over the notes defined in the `melody[]` and `durations[]` arrays. For each note, it calculates the note duration and plays the tone using the `tone()` function. After playing each note, it waits for a pause duration before proceeding to the next note.

## Usage
1. Connect the components as per the provided circuit diagram.
2. Upload the code to your Arduino Uno board.
3. Power on the Arduino Uno.

The melody will start playing on the speaker connected to the circuit.

## Credits
This code was designed by Prince Kushwaha.

