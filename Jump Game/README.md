# Jump Game

This project is a simple game implemented on an Arduino with an LCD screen. The hero moves across the screen, and the player must avoid obstacles by jumping. The score is displayed on the screen, and the game can be restarted by pressing a button.

## Components

- Arduino board
- LCD screen with I2C interface (address 0x27)
- Push button
- Resistors
- 10k ohm Resistor
- Jumper wires
- Breadboard

## Connections

### LCD Screen
- VCC: 5V
- GND: GND
- SDA: A4 (Arduino UNO)
- SCL: A5 (Arduino UNO)

### Push Button
- Connect one leg of the push button to digital pin 2 on the Arduino.
- Connect the other leg of the push button to ground (GND) on the Arduino.
- Optionally, connect a 10k ohm resistor between the pin connected to the push button and ground to avoid floating input when the button is not pressed.

## Setup Instructions

1. Connect the LCD screen to the Arduino using the I2C interface.
2. Connect the push button to the Arduino as described above.
3. Load the provided Arduino sketch onto your Arduino board.
4. Power up the Arduino and the LCD should display "Press Start".
5. Press the button to start the game.

## Game Instructions

1. When the game starts, the hero will run across the bottom of the screen.
2. Press the button to make the hero jump and avoid obstacles.
3. If the hero collides with an obstacle, the game will display "Game Over!!" and show your score.
4. Press the button to restart the game and reset the score.

Enjoy your game!

This code is designed by Prince Kushwaha from COSM Electronics.
