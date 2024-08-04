// This Code is Designed by Prince Kushwaha from COSM Electronics

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with the I2C address 0x27 and the dimensions (16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);


byte glyphs[5][8]={
  {B11111,B11111,B00000,B00000,B00000,B00000,B00000,B00000},
  {B00000,B00000,B00000,B00000,B00000,B00000,B11111,B11111},
  {B11111,B11111,B00000,B00000,B00000,B00000,B11111,B11111},
  {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111},
  {B00000,B00000,B00000,B00000,B00000,B01110,B01110,B01110}
};

const int digitWidth = 3;
const char bigDigitsTop[10][digitWidth]={3,0,3, 0,3,32, 2,2,3, 0,2,3, 3,1,3, 3,2,2, 3,2,2, 0,0,3, 3,2,3, 3,2,3};
const char bigDigitsBot[10][digitWidth]={3,1,3, 1,3,1, 3,1,1, 1,1,3, 32,32,3, 1,1,3, 3,1,3, 32,32,3, 3,1,3, 1,1,3};


char buffer[12];  //used to convert a number into a string

void setup()
{
  lcd.init();
  lcd.backlight();
  for(int i=0; i<5; i++)
  lcd.createChar(i, glyphs[i]);  //create the 5 custom glyphs

  //show a countdown timer
  for(int digit = 9; digit>=0; digit--)
  {
    showDigit(digit, 0);
    delay(1000);  
  }
  lcd.clear();
}
void loop()
{
  int number = millis() / 1000;
  showNumber(number, 0);
  delay(1000);  
}

void showDigit(int digit, int position)
{
  lcd.setCursor(position * (digitWidth + 1), 0);
  for(int i=0; i<digitWidth; i++)
    lcd.print(bigDigitsTop[digit][i]);
  lcd.setCursor(position * (digitWidth + 1), 1);
  for(int i=0; i < digitWidth; i++)
    lcd.print(bigDigitsBot[digit][i]);  
}

void showNumber(int value, int position)
{
  int index;
  itoa(value, buffer, 10);
  for(index = 0; index < 10; index++)
  {
    char c = buffer[index];
    if(c == 0)
      return;
    c = c - 48;
    showDigit(c, position + index);  
  }  
}
