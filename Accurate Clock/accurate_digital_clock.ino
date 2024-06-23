// This Code is Designed by Prince Kushwaha from COSM Electronics
// Simple Clock with Date created just using a Arduino - no RTC module
// Displays time on a 16x2 LCD display
// Buttons to set time
//   Mode button (pin 2) toggles set time, set date and run
//   Button 1 (pin 3) Increments Minutes and Month and decreases Year/speed adj
//   Button 2 (pin 4) Increments Hour and Day and increases Year./speed adj
// 24 Hour display

// Include the library driver for display:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LiquidCrystal lcd( RS, EN, D4,D5, D6, D7)
LiquidCrystal_I2C lcd(0x27, 16, 2); // create an lcd object and assign the I2C address

// Define buttons and buzzer connections
#define MODE_BUTTON 2
#define HOUR_BUTTON 3                  // Same button different definitions to
#define UP_BUTTON 3                    // make code easier to understand 
#define DAY_BUTTON 3
#define MINUTE_BUTTON 4                // Same button different definitions to
#define DOWN_BUTTON 4                  // make code easier to understand 
#define MONTH_BUTTON 4

// Current mode settings
#define SHOW_TIME 1                    // 1 = running - show time
#define SET_TIME  2                    // 2 = time set
#define SET_YEAR  3                    // 3 = year set
#define SET_DATE  4                    // 4 = day/month set 
#define SET_SPEED_ADJ  5               // 5 = amend the speedCorrection variable

int speedCorrection = 3545;            // Number of milliseconds my Nano clock runs slow per hour
// negative number here if it is running fast
// change to match your Arduino

// Volatile variables as changed in an interrupt and we
// need to force the system to read the actual variable
// when used outside the interrupt and not use a cached version
volatile unsigned long currentTime;    // Duration in milliseconds from midnight
unsigned long lastTime = -1000;        // lastTime that ShowTime was called initialised to -1000 so shows immediately
volatile unsigned long elapsed;        // Timer used for delay and hour count

unsigned long millisecondsInADay;      // Milliseconds in 24 hours
unsigned long millisecondsInHour;      // Milliseconds in 1 hour
int currentMode;                       // 1 = running - show time
// 2 = time set
// 3 = year set
// 4 = day/month set

float currentDate;                     // Julian date
float lastDate = 0.0;                  // last date that ShowDate was called
int currentDay;
int currentMonth;
int currentYear;

char *dayArray[] = {  "Tue.  ",       // Will show a compiler warning but works fine
                      "Wed.  ",
                      "Thur. ",
                      "Fri.  ",
                      "Sat.  ",
                      "Sun.  ",
                      "Mon.  "
                   };

void setup() {
  // Set up  time interrupt - millis() rolls over after 50 days so
  // we are using our own millisecond counter which we can reset at
  // the end of each day
  TCCR0A = (1 << WGM01);      //Set the CTC mode Compare time and trigger interrupt
  OCR0A = 0xF9;               //Set value for time to compare to ORC0A for 1ms = 249  (8 bits so max is 256)
  //[(Clock speed/Prescaler value)*Time in seconds] - 1
  //[(16,000,000/64) * .001] - 1 = 249 = 1 millisecond
  TIMSK0 |= (1 << OCIE0A);    //set timer compare interrupt
  TCCR0B |= (1 << CS01);      //Set the prescale 1/64 clock
  TCCR0B |= (1 << CS00);      // ie 110 for last 3 bits
  TCNT0  = 0;                 //initialize counter value to 0
  sei();                      //Enable interrupt

  pinMode(MINUTE_BUTTON, INPUT_PULLUP);
  pinMode(HOUR_BUTTON, INPUT_PULLUP);
  pinMode(MODE_BUTTON, INPUT_PULLUP);
  //pinMode(BUZZER, OUTPUT);
  currentTime = 0;                          // Set to current time to mindnight
  currentDate = JulianDate(1, 1, 2021);     // Set base date
  elapsed = 0;                              // Set period counter to 0
  millisecondsInADay = 24ul * 60 * 60 * 1000;
  millisecondsInHour = 60ul * 60 * 1000;
  currentMode = SHOW_TIME;                  // Initial mode is running and showing time and date
  // Setup LCD
  lcd.init();
  lcd.backlight();
  lcd.noAutoscroll();
  lcd.display();
  lcd.clear();
  ShowTime(currentTime);
}

void loop() {
  // loop runs every 150 milliseconds

  // If at end of the day reset time and increase date
  if ((currentMode == SHOW_TIME) &&
      (currentTime > millisecondsInADay)) {
    //Next day
    // Stop interrupts while reset time
    noInterrupts();
    currentTime -= millisecondsInADay;
    interrupts();
    currentDate++;
  }
  // At the end of each hour adjust the elapsed time for
  // the inacuracy in the Arduino clock
  if (elapsed >= millisecondsInHour) {
    noInterrupts();
    // Adjust time for slow/fast running Arduino clock
    currentTime += speedCorrection;
    // Reset to count the next hour
    elapsed = 0;
    interrupts();
  }

  // Check if any buttons have been pressed
  CheckButtons();

  // Show display based on current mode
  switch (currentMode) {
    case SHOW_TIME:
      // Display current time and date
      ShowTime(currentTime);
      ShowDate(currentDate);
      break;
    case SET_TIME:
      // Display screen for setting the time
      ShowTimeSet(currentTime);
      break;
    case SET_YEAR:
      // Display screen for setting the year
      ShowYearSet(currentDate);
      break;
    case SET_DATE:
      // Display screen for setting the day and month
      ShowDDMMSet(currentDate);
      break;
    case SET_SPEED_ADJ:
      // Display screen for adjusting the speed correction
      ShowSpeedSet();
      break;
  }
  Wait(150);
}

// This is interrupt is called when the compare time has been reached
// hence will be called once a millisecond based on the
// OCR0A register setting.
ISR(TIMER0_COMPA_vect) {
  if (currentMode != SET_TIME)
    currentTime++;
  elapsed++;
}

float JulianDate(int iday, int imonth, int iyear) {
  // Calculate julian date (tested up to the year 20,000)
  unsigned long d = iday;
  unsigned long m = imonth;
  unsigned long y = iyear;
  if (m < 3) {
    m = m + 12;
    y = y - 1;
  }
  unsigned long t1 = (153 * m - 457) / 5;
  unsigned long t2 = 365 * y + (y / 4) - (y / 100) + (y / 400);
  return 1721118.5 + d + t1 + t2;
}

void GregorianDate(float jd, int &iday, int &imonth, int &iyear) {
  // Note 2100 is the next skipped leap year - compensates for skipped leap years
  unsigned long f = jd + 68569.5;
  unsigned long e = (4.0 * f) / 146097;
  unsigned long g = f - (146097 * e + 3) / 4;
  unsigned long h = 4000ul * (g + 1) / 1461001;
  unsigned long t = g - (1461 * h / 4) + 31;
  unsigned long u = (80ul * t) / 2447;
  unsigned long v = u / 11;
  iyear = 100 * (e - 49) + h + v;
  imonth = u + 2 - 12 * v;
  iday = t - 2447 * u / 80;
}

void SplitTime(unsigned long curr, unsigned long &ulHour,
               unsigned long &ulMin, unsigned long &ulSec) {
  // Calculate HH:MM:SS from millisecond count
  ulSec = curr / 1000;
  ulMin = ulSec / 60;
  ulHour = ulMin / 60;
  ulMin -= ulHour * 60;
  ulSec = ulSec - ulMin * 60 - ulHour * 3600;
}

unsigned long SetTime(unsigned long ulHour, unsigned long ulMin,
                      unsigned long ulSec) {
  // Sets the number of milliseconds from midnight to current time
  return (ulHour * 60 * 60 * 1000) +
         (ulMin * 60 * 1000) +
         (ulSec * 1000);
}

void Wait(unsigned long value) {
  // Create our own dealy function
  // We have set our own interrupt on TCCR0A
  // hence millis() and delay() will no longer work
  unsigned long startTime = elapsed;
  while ((elapsed - startTime) < value) {
    // Just wait
  }
}

void CheckButtons() {
  // If the mode button has been pressed pin will go LOW
  if (digitalRead(MODE_BUTTON) == LOW) {
    // Advance to next mode
    switch (currentMode) {
      case SHOW_TIME:
        currentMode = SET_TIME;
        lcd.clear();
        break;
      case SET_TIME:
        currentMode = SET_YEAR;
        lcd.clear();
        break;
      case SET_YEAR:
        currentMode = SET_DATE;
        lcd.clear();
        break;
      case SET_DATE:
        currentMode = SET_SPEED_ADJ;
        lcd.clear();
        break;
      case SET_SPEED_ADJ:
        currentMode = SHOW_TIME;
        lcd.clear();
        // Reset variables so that the display will be forced to update
        // the next time ShowTime and ShowDate are called
        lastTime = 0;
        lastDate = 0.0;
        break;
    }
  }
  if (currentMode != SHOW_TIME) {
    switch (currentMode) {
      // If mode anyhting other than SHOW_TIME check buttons
      // Pin goes LOW when ssociated button pressed
      case SET_TIME:
        if (digitalRead(MINUTE_BUTTON) == LOW) {
          // Advance minute
          unsigned long iHours;
          unsigned long iMinutes;
          unsigned long iSeconds;
          SplitTime(currentTime, iHours, iMinutes, iSeconds);
          if (iMinutes < 59) {
            iMinutes++;
          }
          else {
            iMinutes = 0;
          }
          // Set stored milliseconds based on current setting
          noInterrupts();
          currentTime = SetTime(iHours, iMinutes, 0);
          elapsed = 0;
          interrupts();
        }
        if (digitalRead(HOUR_BUTTON) == LOW) {
          // Advance hour
          unsigned long iHours;
          unsigned long iMinutes;
          unsigned long iSeconds;
          SplitTime(currentTime, iHours, iMinutes, iSeconds);
          if (iHours < 23) {
            iHours++;
          }
          else {
            iHours = 0;
          }
          // Set stored milliseconds based on current setting
          noInterrupts();
          currentTime = SetTime(iHours, iMinutes, 0);
          elapsed = 0;
          interrupts();
        }
        break;
      case SET_YEAR:
        if (digitalRead(UP_BUTTON) == LOW) {
          // Increase year
          int iDay;
          int iMonth;
          int iYear;
          GregorianDate(currentDate, iDay, iMonth, iYear);
          iYear++;
          // Set stored date based on current settings
          currentDate = JulianDate(iDay, iMonth, iYear);
        }
        if (digitalRead(DOWN_BUTTON) == LOW) {
          // Decrease year
          int iDay;
          int iMonth;
          int iYear;
          GregorianDate(currentDate, iDay, iMonth, iYear);
          iYear--;
          // Set stored date based on current settings
          currentDate = JulianDate(iDay, iMonth, iYear);
        }
        break;
      case SET_DATE:
        if (digitalRead(MONTH_BUTTON) == LOW) {
          // Advance month
          int iDay;
          int iMonth;
          int iYear;
          GregorianDate(currentDate, iDay, iMonth, iYear);
          iMonth++;
          if (iMonth > 12) {
            iMonth = 1;
          }
          // Set stored date based on current settings
          currentDate = JulianDate(iDay, iMonth, iYear);
        }
        if (digitalRead(DAY_BUTTON) == LOW) {
          // Advance day
          int iDay;
          int iMonth;
          int iYear;
          GregorianDate(currentDate, iDay, iMonth, iYear);
          iDay++;
          if (iDay > 31) {
            iDay = 1;
          }
          if (((iMonth == 4) || (iMonth == 6) || (iMonth == 9) || (iMonth == 11))
              && (iDay > 30)) {
            iDay = 1;
          }
          if ((iMonth == 2) && (iDay > 29)) {
            iDay = 1;
          }
          if ((iMonth == 2) && ((iYear % 4) != 0) && (iDay > 28)) {
            iDay = 1;
          }
          // Set stored date based on current settings
          // If subsequently adjust the month so day is not valid
          // then display will advance to next valid date
          currentDate = JulianDate(iDay, iMonth, iYear);
        }
        break;
      case SET_SPEED_ADJ:
        // increase or decrease correcton by 5 milliseconds
        if (digitalRead(UP_BUTTON) == LOW) {
          speedCorrection += 5;
        }
        if (digitalRead(DOWN_BUTTON) == LOW) {
          speedCorrection -= 5;
        }
        break;
    }
  }
}

String FormatNumber(int value) {
  // To add a leading 0 if required
  if (value < 10) {
    return "0" + String(value);
  }
  else {
    return String(value);
  }
}

void ShowTime(unsigned long value) {
  // Update display once a second
  // or when rolls over midnight
  if ((value > lastTime + 1000) || (value < lastTime)) {
    lastTime = value;
    unsigned long iHours;
    unsigned long iMinutes;
    unsigned long iSeconds;
    SplitTime(value, iHours, iMinutes, iSeconds);

    // Display the time on line 0
    lcd.setCursor(0, 0);
    lcd.print("Time: " + FormatNumber(iHours) + ":" +
              FormatNumber(iMinutes) + ":" +
              FormatNumber(iSeconds));
  }
}

void ShowDate(float value) {
  // Update display if date has changed since
  // the date was last displayed
  if (lastDate != value) {
    lastDate = value;
    int iday;
    int imonth;
    int iyear;
    String currentDay;
    GregorianDate(value, iday, imonth, iyear);
    int dayOfWeek = (unsigned long)value % 7;
    // Display the date on line 0
    lcd.setCursor(0, 1);
    lcd.print(dayArray[dayOfWeek]);
    lcd.print(FormatNumber(iday) + ":" +
              FormatNumber(imonth) + ":" +
              iyear);
  }
}

void ShowDDMMSet(float value) {
  int iday;
  int imonth;
  int iyear;
  String currentDay;
  GregorianDate(value, iday, imonth, iyear);
  // Display day and month for adjusting
  lcd.setCursor(0, 0);
  lcd.print("Set day & month:");
  lcd.setCursor(0, 1);
  lcd.print("Day:" + FormatNumber(iday) + " Month:" +
            FormatNumber(imonth));
}


void ShowYearSet(float jd) {
  int iday;
  int imonth;
  int iyear;
  GregorianDate(jd, iday, imonth, iyear);
  // Display year for adjusting
  lcd.setCursor(0, 0);
  lcd.print("Set year:");
  lcd.setCursor(0, 1);
  lcd.print("Year: " + FormatNumber(iyear));
}

void ShowTimeSet(unsigned long value) {
  unsigned long iHours;
  unsigned long iMinutes;
  unsigned long iSeconds;
  // Display time for adjusting
  SplitTime(value, iHours, iMinutes, iSeconds);
  lcd.setCursor(0, 0);
  lcd.print("Set time:");
  lcd.setCursor(0, 1);
  lcd.print("Hours:" + FormatNumber(iHours) + " Mins:" +
            FormatNumber(iMinutes));
}

void ShowSpeedSet() {
  // Display speed correction figure for adjusting
  // could be + or -
  lcd.setCursor(0, 0);
  lcd.print("Set speed adj:");
  lcd.setCursor(0, 1);
  lcd.print("Millis: ");
  lcd.print(speedCorrection);
  lcd.print(" ");
}
