// This code is Designed by Prince Kushwaha from COSM Electronics 

// Include necessary libraries
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD address 0x27 for a 16x2 display

// Pulse Sensor
const int PULSE_SENSOR_PIN = A3; // Analog PIN where the Pulse Sensor is connected
const int LED_PIN = 13;          // On-board LED PIN
const int THRESHOLD = 550;       // Threshold for detecting a heartbeat
PulseSensorPlayground pulseSensor;

// DS18B20 Temperature Sensor
#define ONE_WIRE_BUS 2 // Data pin for the DS18B20
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float bodyTempC = 0.0; // Temperature in Celsius
float bodyTempF = 0.0; // Temperature in Fahrenheit

void setup()
{
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Configure Pulse Sensor
  pulseSensor.analogInput(PULSE_SENSOR_PIN);
  pulseSensor.blinkOnPulse(LED_PIN);
  pulseSensor.setThreshold(THRESHOLD);

  // Check if Pulse Sensor is initialized
  if (pulseSensor.begin())
  {
    Serial.println("PulseSensor object created successfully!");
  }

  // Initialize DS18B20 Sensor
  sensors.begin();

  // Welcome message
  lcd.setCursor(0, 0);
  lcd.print("Health Monitor");
  delay(2000);
  lcd.clear();
}

void loop()
{
  // Read the current BPM
  int currentBPM = pulseSensor.getBeatsPerMinute();

  // Check if a heartbeat is detected
  if (pulseSensor.sawStartOfBeat())
  {
    Serial.println("♥ A HeartBeat Happened!");
    Serial.print("BPM: ");
    Serial.println(currentBPM);

    // Display heart rate on the LCD
    lcd.setCursor(0, 0);
    lcd.print("Pulse: ");
    lcd.print(currentBPM);
    lcd.print(" BPM ");
  }

  // Read body temperature
  sensors.requestTemperatures();
  bodyTempC = sensors.getTempCByIndex(0); // Read temperature in Celsius
  bodyTempF = bodyTempC * 1.8 + 32;       // Convert Celsius to Fahrenheit

  // Display body temperature on the LCD
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(bodyTempF);
  lcd.print(" F");

  // Print temperature to the Serial Monitor
  Serial.print("Body Temp (C): ");
  Serial.print(bodyTempC);
  Serial.print(" | Body Temp (F): ");
  Serial.println(bodyTempF);

  // Add a small delay for readability
  delay(1000);
}
