# Arduino Buzzer Music Player 🎶

This project demonstrates how to generate melodies using a buzzer and Arduino. The code is designed to play a sequence of musical notes with varying durations, creating a complete melody.

---

## Project Overview

This project uses an Arduino-compatible microcontroller and a buzzer to produce music by generating tones of specific frequencies for specific durations. The melody is defined as arrays of musical notes (`melody[]`) and their respective durations (`durations[]`), which are played sequentially.

---

## Features

- Plays a predefined melody using a buzzer.
- Configurable tones and durations for creating custom melodies.
- Demonstrates the usage of the `tone()` and `noTone()` functions to generate sound.
- Simple and easy-to-understand implementation for beginners in Arduino projects.

---

## Components Required

1. **Microcontroller** (e.g., Arduino Uno, Mega, or compatible board)
2. **Buzzer** (Piezoelectric or similar)
3. **Connecting Wires**
4. **Breadboard** (optional, for prototyping)

---

## Circuit Diagram

1. Connect the positive terminal of the buzzer to the designated pin on the microcontroller (`BUZZER_PIN` in the code, set to pin 5).
2. Connect the negative terminal of the buzzer to the GND pin on the microcontroller.

---

## How It Works

1. **Tone Generation**: 
   - The `tone()` function generates a square wave of a specified frequency on the buzzer pin.
   - Frequencies are defined using musical note constants (e.g., `NOTE_CS4`, `NOTE_E4`) from the `pitches.h` file.

2. **Timing Control**:
   - The duration of each note is determined by the `durations[]` array.
   - A small pause is added between notes for better auditory distinction.

3. **Playback Loop**:
   - The `loop()` function iterates through the `melody[]` and `durations[]` arrays, playing each note one by one.

---

## Code Structure

- **Setup**: Initializes the buzzer pin as an output.
- **Loop**: Plays the melody continuously in a loop.
- **Note Definitions**: Uses the `pitches.h` file for predefined note frequencies.

---

## Usage Instructions

1. Upload the code to your Arduino-compatible board using the Arduino IDE.
2. Connect the buzzer and ensure the wiring matches the circuit diagram.
3. Power the microcontroller. The buzzer will start playing the melody.

---

## Applications

- Educational projects to understand sound generation with microcontrollers.
- Alarm or notification systems.
- Creative musical projects with Arduino.

---

## Credits

This project is designed and developed by **Prince Kushwaha** from COSM Electronics.

---

## License

This project is open-source and available for educational and personal use. Attribution is appreciated if you use or modify this project.

---

Happy tinkering and enjoy the melody! 🎶
