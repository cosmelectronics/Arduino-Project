# Automatic College Bell Project Using Arduino

This Arduino project automates the college bell system. You can set the number of periods and their respective durations using an I2C 16x2 LCD and control buttons. A buzzer alerts at the end of each period, making it an efficient solution for managing class schedules.

## Author

This project is designed by Prince Kushwaha from COSM Electronics.

## Components Needed

- Arduino board
- 16x2 I2C LCD
- 3 Push buttons
- Buzzer
- Connecting wires
- Breadboard

## Circuit Diagram

1. **I2C LCD Connections:**
    - VCC to 5V
    - GND to GND
    - SDA to A4
    - SCL to A5

2. **Button Connections:**
    - UP button to digital pin 6
    - DOWN button to digital pin 5
    - SET button to digital pin 4

3. **Buzzer Connection:**
    - Buzzer to digital pin 3

## Features

- **Set Number of Periods:** Use the UP and DOWN buttons to set the number of periods.
- **Set Duration for Each Period:** Set the time for each period using the UP and DOWN buttons.
- **Automatic Bell Alert:** A buzzer sounds at the end of each period.

## Usage

1. **Initialize the System:**
    - Connect the components as described in the circuit diagram.
    - Upload the provided code to your Arduino board.

2. **Set Number of Periods:**
    - Use the UP and DOWN buttons to adjust the number of periods.
    - Press the SET button to confirm the number of periods.

3. **Set Duration for Each Period:**
    - Use the UP and DOWN buttons to adjust the duration for each period.
    - Press the SET button to confirm the duration for each period.

4. **Start the Periods:**
    - The system will automatically start the periods and sound the buzzer at the end of each period.

## Code Overview

Here are some key parts of the code:

- **Initialization:**
    ```cpp
    LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust the address as needed
    ```

- **Pin Configuration:**
    ```cpp
    const int UP_BUTTON = 6;
    const int DOWN_BUTTON = 5;
    const int SET_BUTTON = 4;
    const int BUZZER_PIN = 3;
    ```

- **Initialize Pins:**
    ```cpp
    void initializePins() {
        pinMode(UP_BUTTON, INPUT);
        pinMode(DOWN_BUTTON, INPUT);
        pinMode(SET_BUTTON, INPUT);
        pinMode(BUZZER_PIN, OUTPUT);
        digitalWrite(UP_BUTTON, HIGH);
        digitalWrite(DOWN_BUTTON, HIGH);
        digitalWrite(SET_BUTTON, HIGH);
    }
    ```

- **Set Number of Periods:**
    ```cpp
    void setNumberOfPeriods() {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Set Periods:");

        while (true) {
            lcd.setCursor(0, 1);
            lcd.print(numPeriods);
            if (digitalRead(UP_BUTTON) == LOW) {
                delay(300);
                numPeriods++;
            } else if (digitalRead(DOWN_BUTTON) == LOW) {
                delay(300);
                numPeriods--;
            } else if (digitalRead(SET_BUTTON) == LOW) {
                delay(300);
                break;
            }
        }
    }
    ```

- **Start the Periods:**
    ```cpp
    void startPeriods() {
        for (currentPeriod = 1; currentPeriod <= numPeriods; currentPeriod++) {
            lcd.clear();
            lcd.setCursor(1, 0);
            lcd.print("Period:");
            lcd.setCursor(10, 0);
            lcd.print(currentPeriod);

            for (int elapsed = 0; elapsed <= periodTimes[currentPeriod]; elapsed++) {
                lcd.setCursor(0, 1);
                lcd.print(elapsed);
                delay(1000);
                if (elapsed == periodTimes[currentPeriod]) {
                    tone(BUZZER_PIN, 200);  // Activate buzzer
                    delay(3000);
                    noTone(BUZZER_PIN);     // Deactivate buzzer
                }
            }
            lcd.clear();
        }
    }
    ```

## License

This project is Designed by Prince Kushwaha, CEO of COSM Electronics.
