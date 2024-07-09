// This Code is Designed by Prince Kushwaha from COSM Electronics

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with the I2C address (usually 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust the address as needed

// Define constants for button and buzzer pins
const int UP_BUTTON = 6;
const int DOWN_BUTTON = 5;
const int SET_BUTTON = 4;
const int BUZZER_PIN = 3;

// Variables to keep track of periods and their times
int numPeriods = 0;
int currentPeriod = 0;
int periodTime = 0;
int periodTimes[12] = {0};

// Function to initialize pin modes and default states
void initializePins() {
    pinMode(UP_BUTTON, INPUT);
    pinMode(DOWN_BUTTON, INPUT);
    pinMode(SET_BUTTON, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(UP_BUTTON, HIGH);
    digitalWrite(DOWN_BUTTON, HIGH);
    digitalWrite(SET_BUTTON, HIGH);
}

// Function to set the number of periods
void setNumberOfPeriods() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Set Periods:");

    while (true) {
        lcd.setCursor(0, 1);
        lcd.print(numPeriods);
        
        // Increase period count
        if (digitalRead(UP_BUTTON) == LOW) {
            delay(300);
            numPeriods++;
        } 
        // Decrease period count
        else if (digitalRead(DOWN_BUTTON) == LOW) {
            delay(300);
            numPeriods--;
        } 
        // Confirm the number of periods
        else if (digitalRead(SET_BUTTON) == LOW) {
            delay(300);
            break;
        }
    }
}

// Function to set the time for each period
void setPeriodTimes() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Set Periods Time");
    delay(1500);
    lcd.clear();

    for (currentPeriod = 1; currentPeriod <= numPeriods; currentPeriod++) {
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Period");
        lcd.setCursor(10, 0);
        lcd.print(currentPeriod);

        while (true) {
            lcd.setCursor(0, 1);
            lcd.print(periodTime);
            
            // Increase period time
            if (digitalRead(UP_BUTTON) == LOW) {
                delay(300);
                periodTime += 10;
            } 
            // Decrease period time
            else if (digitalRead(DOWN_BUTTON) == LOW) {
                delay(300);
                periodTime -= 10;
                if (periodTime < 0) {
                    periodTime = 0;
                }
            } 
            // Confirm the period time
            else if (digitalRead(SET_BUTTON) == LOW) {
                delay(300);
                break;
            }
        }
        periodTimes[currentPeriod] = periodTime;
        periodTime = 0;
    }
}

// Function to start the periods and trigger the buzzer
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

// Arduino setup function
void setup() {
    lcd.init();  // Initialize the LCD
    lcd.backlight();  // Turn on the backlight
    initializePins();
}

// Arduino main loop function
void loop() {
    setNumberOfPeriods();
    setPeriodTimes();
    startPeriods();

    // Reset variables for the next loop
    numPeriods = 0;
    currentPeriod = 0;
    periodTime = 0;
    memset(periodTimes, 0, sizeof(periodTimes));
}
