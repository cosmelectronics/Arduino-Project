// This Code is Designed by Prince Kushwaha from COSM Electronics

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ntc_pin A0          // Pin, to which the voltage divider is connected
#define vd_power_pin 2      // 5V for the voltage divider
#define nominal_resistance 10000  // Nominal resistance at 25⁰C
#define nominal_temperature 25    // Temperature for nominal resistance (almost always 25⁰C)
#define samplingrate 5      // Number of samples
#define beta 3950           // The beta coefficient or the B value of the thermistor (usually 3000-4000) check the datasheet for the accurate value.
#define Rref 10000          // Value of resistor used for the voltage divider

int samples = 0;            // Variable to store the samples

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD I2C address to 0x27 for a 16 chars and 2 line display

void setup(void) {
  pinMode(vd_power_pin, OUTPUT);
  Serial.begin(9600);       // Initialize serial communication at a baud rate of 9600
  lcd.init();               // Initialize the LCD
  lcd.backlight();          // Turn on the backlight
}

void loop(void) {
  uint8_t i;
  float average;
  samples = 0;

  // Take voltage readings from the voltage divider
  digitalWrite(vd_power_pin, HIGH);
  for (i = 0; i < samplingrate; i++) {
    samples += analogRead(ntc_pin);
    delay(10);
  }
  digitalWrite(vd_power_pin, LOW);
  
  average = 0;
  average = samples / samplingrate;
  
  Serial.print("ADC readings ");
  Serial.println(average);
  lcd.setCursor(0, 0);
  lcd.print("ADC: ");
  lcd.print(average);

  // Calculate NTC resistance
  average = 1023 / average - 1;
  average = Rref / average;
  
  Serial.print("Thermistor R ");
  Serial.println(average);
  lcd.setCursor(0, 1);
  lcd.print("R: ");
  lcd.print(average);

  float temperature;
  temperature = average / nominal_resistance;       // (R/Ro)
  temperature = log(temperature);                   // ln(R/Ro)
  temperature /= beta;                              // 1/B * ln(R/Ro)
  temperature += 1.0 / (nominal_temperature + 273.15); // + (1/To)
  temperature = 1.0 / temperature;                  // Invert
  temperature -= 273.15;                            // Convert absolute temp to C

  Serial.print("Temp ");
  Serial.print(temperature);
  Serial.println(" *C");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  delay(1000);
}
