# 🌱 Arduino Soil Moisture Percentage Measurement System

This project demonstrates a **Soil Moisture Percentage Measurement System using Arduino UNO and a 16×2 I2C LCD display**. It measures soil moisture levels in real time and converts raw sensor readings into an accurate **percentage value (0%–100%)**, making it ideal for smart irrigation and plant monitoring applications.

The project is developed and documented by **Prince Kushwaha – COSM Electronics**.

---

## 📌 Project Overview

* Reads analog data from a soil moisture sensor
* Converts raw values into moisture percentage using calibration
* Displays moisture percentage and raw sensor value on a 16×2 I2C LCD
* Provides stable readings using averaging
* Suitable for agriculture, gardening, and automation projects

---

## 🔧 Components Used

* Arduino UNO R3
* Soil Moisture Sensor (Analog type)
* 16×2 LCD Display
* I2C Module
* Mini Breadboard
* Jumper Wires

---

## 🔌 Pin Connections

### Soil Moisture Sensor

* VCC → 5V (Arduino)
* GND → GND (Arduino)
* AO  → A0 (Arduino)

### I2C LCD

* SDA → A4 (Arduino UNO)
* SCL → A5 (Arduino UNO)
* VCC → 5V
* GND → GND

---

## ⚙️ Calibration Details

This project uses **manual calibration** to ensure accurate moisture percentage calculation.

Based on testing:

* **Wet condition (sensor in water):**
  Raw value ≈ 260–300 → `WET_VALUE = 280`

* **Dry condition (sensor outside water):**
  Raw value ≈ 900–915 → `DRY_VALUE = 910`

These values are already configured inside the sketch file.

> ⚠️ Note: Calibration values may vary depending on the sensor and environment. Recalibrate if you use a different sensor.

---

## ▶️ How to Use

1. Connect all components according to the wiring section
2. Open `soil_moisture_sensor.ino` in Arduino IDE
3. Install **LiquidCrystal_I2C** library via Library Manager
4. Select **Arduino UNO** and the correct COM port
5. Upload the sketch
6. Observe moisture percentage on the LCD and Serial Monitor

---

## 🌾 Applications

* Smart irrigation systems
* Home gardening
* Agriculture automation
* Greenhouse monitoring
* Plant health monitoring

---

## 🛠️ Notes & Recommendations

* Avoid keeping resistive soil sensors permanently powered to reduce corrosion
* For long-term use, consider capacitive soil moisture sensors
* LCD I2C address may vary (`0x27` or `0x3F`)

---

## 👤 Author

**Prince Kushwaha**
COSM Electronics

👉 Follow **@cosmelectronics** for more electronics projects

---

## 📜 License

This project is open-source and intended for **educational and non-commercial use**.
Feel free to modify and improve it with proper credit.
