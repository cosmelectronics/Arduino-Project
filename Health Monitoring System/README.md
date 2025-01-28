# Health Monitoring System  

## Project Description  
This project is a **Health Monitoring System** designed to measure and display the **heart rate (BPM)** and **body temperature** on a **16x2 LCD** using an **Arduino UNO**. The system incorporates a **Pulse Sensor** for detecting the heart rate and a **DS18B20 digital temperature sensor** for measuring body temperature. The temperature is displayed in both Celsius and Fahrenheit.

This project is designed by **Prince Kushwaha** from **COSM Electronics**.  

---

## Features  
- Real-time measurement of **heart rate** (BPM).  
- Accurate measurement of **body temperature** in both Celsius and Fahrenheit.  
- Display data on a **16x2 LCD** using the I2C module.  
- Outputs data to the **Serial Monitor** for debugging purposes.  
- On-board LED blinks on each detected heartbeat.

---

## Components Used  
1. **Arduino UNO**  
2. **Pulse Sensor**  
3. **DS18B20 Digital Temperature Sensor**  
4. **16x2 LCD Display with I2C Module**  
5. **10k Ohm Pull-up Resistor** (for DS18B20)  
6. **Connecting Wires**  
7. **Breadboard**  

---

## Circuit Connections  

### **Pulse Sensor**:  
| Pulse Sensor Pin | Arduino Pin  |  
|------------------|--------------|  
| Signal           | A3           |  
| VCC              | 5V           |  
| GND              | GND          |  

### **DS18B20 Temperature Sensor**:  
| DS18B20 Pin | Arduino Pin  |  
|-------------|--------------|  
| Data        | D2           |  
| VCC         | 5V           |  
| GND         | GND          |  

**Note**: Use a 10k Ohm pull-up resistor between the **Data** pin and **VCC**.

### **16x2 LCD with I2C Module**:  
| I2C Pin | Arduino Pin |  
|---------|-------------|  
| SDA     | A4          |  
| SCL     | A5          |  
| VCC     | 5V          |  
| GND     | GND         |  

---

## Libraries Required  
The following Arduino libraries are required for this project:  
1. **PulseSensorPlayground**  
2. **LiquidCrystal_I2C**  
3. **OneWire**  
4. **DallasTemperature**  

You can install these libraries from the Arduino Library Manager:  
- Go to **Sketch** → **Include Library** → **Manage Libraries**.  
- Search for the library name and click **Install**.  

---

## How It Works  
1. **Pulse Sensor** detects the heartbeat and calculates the heart rate (BPM).  
2. **DS18B20** measures the body temperature in Celsius, which is converted to Fahrenheit.  
3. The **16x2 LCD** displays:  
   - **Line 1**: `Pulse: <BPM> BPM`  
   - **Line 2**: `Temp: <Temperature in F>`  
4. Data is also printed to the Serial Monitor for real-time debugging.  
5. The on-board **LED (Pin 13)** blinks with each heartbeat detected.  

---

## Setup Instructions  
1. Connect all components as per the circuit connections mentioned above.  
2. Install the required libraries in the Arduino IDE.  
3. Upload the code to the Arduino UNO.  
4. Power the Arduino UNO via USB or an external power source.  
5. Observe the heart rate and body temperature displayed on the 16x2 LCD and the Serial Monitor.  

---

## Output Example  
- **LCD Output**:  
  ```
  Pulse: 72 BPM  
  Temp: 98.6 F  
  ```

- **Serial Monitor Output**:  
  ```
  ♥ A HeartBeat Happened!  
  BPM: 72  
  Body Temp (C): 37.0 | Body Temp (F): 98.6  
  ```

---

## Applications  
- Personal health monitoring.  
- Fitness tracking systems.  
- Remote patient monitoring.  

---

## Author  
**Prince Kushwaha**  
FOllow **COSM Electronics** for more Projects.
