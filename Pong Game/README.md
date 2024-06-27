# Arduino Pong Game on 16x2 LCD with I2C

This project is a simple Pong game implemented on an Arduino UNO with a 16x2 LCD (I2C) and two push buttons. The player controls a paddle to hit the ball, and the game keeps track of the score. When the ball misses the paddle, the game displays the final score and prompts the player to restart the game.

## Components Needed

- Arduino UNO
- 16x2 LCD with I2C module
- 2 Push buttons
- Jumper wires
- Breadboard

## Circuit Diagram

### LCD with I2C Module:
- **VCC** to 5V on the Arduino UNO
- **GND** to GND on the Arduino UNO
- **SDA** to A4 on the Arduino UNO
- **SCL** to A5 on the Arduino UNO

### Push Buttons:
- One side of the first button to **GND** on the Arduino UNO
- The other side of the first button to **digital pin 2** on the Arduino UNO
- One side of the second button to **GND** on the Arduino UNO
- The other side of the second button to **digital pin 3** on the Arduino UNO

## Code Highlights

- **LCD Initialization**: The LCD is initialized using the I2C address `0x27`.
- **Button Handling**: The buttons are used to move the paddle up and down.
- **Ball Movement**: The ball moves within the boundaries of the LCD screen. It bounces back when it hits the walls or the paddle.
- **Paddle Movement**: The paddle is displayed on the right side of the screen and moves up or down based on the button presses.
- **Score Tracking**: The score increases when the ball collides with the paddle or the left wall.
- **Game Over Condition**: The game displays "Game Over!" and the final score when the ball misses the paddle.
- **Restart Game**: After displaying the game over message and score for 3 seconds, the game prompts the player to press any button to restart the game.

## How to Use

1. **Setup the Circuit**: Connect the LCD, push buttons, and Arduino UNO as described in the circuit diagram.
2. **Upload the Code**: Upload the provided code to the Arduino UNO.
3. **Start the Game**: The game will start automatically. Use the buttons to move the paddle up and down.
4. **Game Over**: When the ball misses the paddle, the game will display "Game Over!" and the score.
5. **Restart the Game**: After 3 seconds, a prompt will appear to press any button to restart the game. Press any button to play again.

## License

This project is designed by Prince Kushwaha from COSM Electronics.
