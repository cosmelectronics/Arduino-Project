// This Code is Designed by Prince Kushwaha
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 (you may need to adjust this)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust for your LCD dimensions if different

const char *scrollText = "Hello!! from COSM Electronics... Subscribe My Channel  ";
int displayWidth = 16; // The width of the LCD

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Get the length of the text
  int textLength = strlen(scrollText);

  // Scroll the text
  for (int i = 0; i < textLength; i++) {
    lcd.clear();

    // Create a temporary string to hold the display part of the text
    char displayText[displayWidth + 1];

    // Copy the part of the text that fits the display width
    for (int j = 0; j < displayWidth; j++) {
      // Use modulo to wrap around the text
      displayText[j] = scrollText[(i + j) % textLength];
    }
    
    // Null terminate the string
    displayText[displayWidth] = '\0';

    // Print the text to the LCD
    lcd.setCursor(0, 0);
    lcd.print(displayText);

    // Delay before scrolling to the next position
    delay(300);
  }
}
