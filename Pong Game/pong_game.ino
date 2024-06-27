// This Code is Designed by Prince Kushwaha from COSM Electronics

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define button pins
const int buttonUpPin = 2;
const int buttonDownPin = 3;

// Ball position
int ballX = 7;
int ballY = 0;

// Ball direction
int ballDirectionX = 1;
int ballDirectionY = 1;

// Paddle position
int paddleY = 0;

// Score
int score = 0;

// Game state
bool gameOver = false;

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();

  // Initialize the button pins
  pinMode(buttonUpPin, INPUT_PULLUP);
  pinMode(buttonDownPin, INPUT_PULLUP);

  // Initial display
  startGame();
}

void loop() {
  if (!gameOver) {
    // Read button states
    int buttonUpState = digitalRead(buttonUpPin);
    int buttonDownState = digitalRead(buttonDownPin);

    // Move paddle up
    if (buttonUpState == LOW && paddleY > 0) {
      lcd.setCursor(15, paddleY);
      lcd.print(" ");
      paddleY--;
    }

    // Move paddle down
    if (buttonDownState == LOW && paddleY < 1) {
      lcd.setCursor(15, paddleY);
      lcd.print(" ");
      paddleY++;
    }

    // Update paddle position
    lcd.setCursor(15, paddleY);
    lcd.print("|");

    // Move ball
    lcd.setCursor(ballX, ballY);
    lcd.print(" ");
    ballX += ballDirectionX;
    ballY += ballDirectionY;

    // Ball collision with walls
    if (ballX == 0) {
      ballDirectionX = -ballDirectionX;
      score++;
    }
    if (ballY == 0 || ballY == 1) {
      ballDirectionY = -ballDirectionY;
    }

    // Ball collision with paddle
    if (ballX == 14 && ballY == paddleY) {
      ballDirectionX = -ballDirectionX;
      score++;
    }

    // Check for game over (ball misses the paddle)
    if (ballX > 15) {
      gameOver = true;
    }

    // Update ball position
    lcd.setCursor(ballX, ballY);
    lcd.print("O");

    // Delay for a bit
    delay(200);
  } else {
    // Display game over and score
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game Over!");
    lcd.setCursor(0, 1);
    lcd.print("Score: ");
    lcd.print(score);
    delay(3000);  // Wait for 3 seconds

    // Show restart message
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Press any Button");
    lcd.setCursor(0, 1);
    lcd.print("to Start Game");

    // Wait for button press to restart
    while (digitalRead(buttonUpPin) == HIGH && digitalRead(buttonDownPin) == HIGH) {
      delay(10);
    }

    // Restart game
    startGame();
  }
}

void startGame() {
  // Reset variables
  ballX = 7;
  ballY = 0;
  ballDirectionX = 1;
  ballDirectionY = 1;
  paddleY = 0;
  score = 0;
  gameOver = false;

  // Initial display
  lcd.clear();
  lcd.setCursor(ballX, ballY);
  lcd.print("O");
  lcd.setCursor(15, paddleY);
  lcd.print("|");
}
