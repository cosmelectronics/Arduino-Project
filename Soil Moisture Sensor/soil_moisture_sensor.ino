// This Code is Written by Prince Kushwaha from COSM Electronics 
// Soil moisture percent display for Arduino UNO
// Uses: Soil sensor analog to A0, I2C 16x2 LCD (SDA->A4, SCL->A5)
// Calibrated with user's measurements:
//   Wet (in water): ~260 - 300  => WET_VALUE = 280
//   Dry (outside water): ~900 - 915 => DRY_VALUE = 910
//
// Library needed: LiquidCrystal_I2C
// Install via Library Manager if not present.

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SOIL_PIN A0
#define AVG_READS 10        // increase for smoother readings
#define UPDATE_MS 900      // display update interval

// Calibration values (use the numbers you reported)
const int DRY_VALUE = 910;  // raw when probe is dry / outside water
const int WET_VALUE = 280;  // raw when probe is in water

LiquidCrystal_I2C lcd(0x27, 16, 2); // change to 0x3F if your LCD address is different

// Utility: clamp integer
int clampInt(int v, int lo, int hi) {
  if (v < lo) return lo;
  if (v > hi) return hi;
  return v;
}

int readAverage() {
  long sum = 0;
  for (int i = 0; i < AVG_READS; i++) {
    sum += analogRead(SOIL_PIN);
    delay(15);
  }
  return (int)(sum / AVG_READS);
}

int rawToPercent(int raw) {
  // We want: raw == DRY_VALUE  -> 0%
  //          raw == WET_VALUE   -> 100%
  // Because DRY_VALUE > WET_VALUE for your sensor, we compute:
  if (DRY_VALUE == WET_VALUE) return 0; // safety
  // Compute normalized value (0..1): (DRY - raw) / (DRY - WET)
  float denom = (float)(DRY_VALUE - WET_VALUE);
  float normalized = ((float)DRY_VALUE - (float)raw) / denom;
  if (normalized < 0.0) normalized = 0.0;
  if (normalized > 1.0) normalized = 1.0;
  int pct = (int)round(normalized * 100.0);
  return pct;
}

String percentBar(int pct) {
  // Create a simple 10-char progress bar (█ style would require custom chars; use #)
  int bars = (pct * 10) / 100;
  String s = "[";
  for (int i = 0; i < 10; i++) {
    s += (i < bars) ? "#" : "-";
  }
  s += "]";
  return s;
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Soil Moisture");
  lcd.setCursor(0,1);
  lcd.print("Initializing...");
  delay(800);
  lcd.clear();
}

void loop() {
  int raw = readAverage();
  int pct = rawToPercent(raw);
  raw = clampInt(raw, 0, 1023);

  // Serial output for debugging/calibration
  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print("  -> ");
  Serial.print(pct);
  Serial.println("%");

  // LCD display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moist: ");
  // keep it compact so it fits: "Moist:  72%"
  if (pct < 10) lcd.print(" "); // alignment
  lcd.print(pct);
  lcd.print("%");

  // second line: raw and small bar
  lcd.setCursor(0, 1);
  String bar = percentBar(pct); // 12 chars -> will truncate to fit
  // show "Raw:280 [###-----]" but truncated to 16 chars
  char buf[17];
  snprintf(buf, 17, "R:%4d %s", raw, bar.c_str());
  lcd.print(buf);

  delay(UPDATE_MS);
}
