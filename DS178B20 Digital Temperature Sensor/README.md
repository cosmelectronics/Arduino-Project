# DS18B20 Temperature Sensor with Arduino UNO and 16x2 LCD (I2C Module)

This project demonstrates how to interface the **DS18B20 digital temperature sensor** with an **Arduino UNO** and display temperature readings in both Celsius and Fahrenheit on a **16x2 LCD screen** using an **I2C module**.

---

## Features
- Reads temperature from the DS18B20 sensor in Celsius and Fahrenheit.
- Displays the temperature readings on a 16x2 LCD.
- Handles sensor disconnection with an error message.
- Debugs temperature readings via the Serial Monitor.

---

## Components Required
1. **Arduino UNO** (or compatible board)
2. **DS18B20 Digital Temperature Sensor**
3. **16x2 LCD Display** with **I2C Module**
4. **4.7kΩ Resistor** (for pull-up on the DS18B20 data line)
5. Jumper wires
6. Breadboard

---

## Circuit Diagram
### Connections for DS18B20:
| **Pin**       | **Connection**                |
|---------------|-------------------------------|
| VCC           | 5V                           |
| GND           | GND                          |
| DATA          | Digital Pin 2 (with 4.7kΩ pull-up resistor to VCC) |

### Connections for I2C LCD:
| **Pin**       | **Connection**                |
|---------------|-------------------------------|
| VCC           | 5V                           |
| GND           | GND                          |
| SDA           | A4                           |
| SCL           | A5                           |

---

## How It Works
1. The DS18B20 sensor measures the temperature in Celsius.
2. The temperature is converted to Fahrenheit using the formula:
   \[
   F = C \times \frac{9}{5} + 32
   \]
3. The temperature readings are displayed on the 16x2 LCD:
   - Line 1: Temperature in Celsius (e.g., `Temp: 25.0°C`)
   - Line 2: Temperature in Fahrenheit (e.g., `Temp: 77.0°F`)
4. If the sensor is disconnected, an error message (`Sensor Error!`) is displayed.

---

## Required Libraries
Ensure the following libraries are installed in your Arduino IDE:
1. **OneWire** - For DS18B20 communication.
2. **DallasTemperature** - For handling temperature data.
3. **LiquidCrystal_I2C** - For I2C-based LCD interaction.

To install these libraries:
1. Go to `Sketch > Include Library > Manage Libraries...`.
2. Search for the library by name and click `Install`.

---

## How to Use
1. Connect the components as per the circuit diagram.
2. Install the required libraries in the Arduino IDE.
3. Upload the provided code to your Arduino UNO.
4. Open the Serial Monitor (set to 9600 baud) to debug temperature readings.
5. Observe the temperature readings on the LCD in real-time.

---

## Expected Output
- **LCD Display**:
  ```
  Temp: 25.0°C
  Temp: 77.0°F
  ```
- **Serial Monitor**:
  ```
  Temperature (C): 25.0
  Temperature (F): 77.0
  ```

---

## Author
This code and project were created by **Prince Kushwaha** from **COSM Electronics**.

---

## License
This project is open-source and can be freely used, modified, and distributed for educational and personal use.
