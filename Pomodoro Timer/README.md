
# Arduino Pomodoro Timer

## Project Overview
This simple project uses an Arduino UNO to create a Pomodoro Timer with LED indicators and a buzzer. It helps users focus by timing 25-minute work sessions and 5-minute breaks. A button is used to start the timer.

## Features
- 25-minute work session  
- 5-minute break  
- Buzzer alerts at transitions  
- LED color changes for work/break  

## Components Required
- Arduino UNO  
- Red LED  
- Green LED  
- Buzzer  
- Push Button  
- 220Ω Resistors  
- Breadboard and Jumper Wires  

## Circuit Connections

| Component    | Arduino UNO Pin     |
|--------------|----------------------|
| Red LED      | D3 (via 220Ω resistor) |
| Green LED    | D4 (via 220Ω resistor) |
| Buzzer       | D5                   |
| Push Button  | D2 (with pull-down resistor) |

## Working Principle
- Press the button to start a 25-minute work session (Red LED on).
- After 25 minutes, the timer switches to a 5-minute break (Green LED on).
- The buzzer alerts the user at each transition.
- After the break, the session ends and the system resets.

## Usage Instructions
1. Connect all components according to the table above.
2. Upload the `pomodoro_timer.ino` sketch to your Arduino UNO.
3. Open the Serial Monitor (9600 baud) for status messages.
4. Press the button to start the Pomodoro timer cycle.

## Author
Created by [KappaNone](https://github.com/KappaNone).

## License
This project is open-source and available for educational and personal use.
