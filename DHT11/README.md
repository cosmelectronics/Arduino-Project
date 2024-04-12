# Project Readme

This project utilizes a DHT11 temperature and humidity sensor along with an Arduino UNO board. However, you can substitute any other sensor, with corresponding changes in the code according to the model. Here's how to set it up:

## Hardware Setup

### DHT Sensor Connection:
- **VCC**: 5.5V
- **DATA**: PIN 4 (alternatively, you can use pins 3, 4, 5, 12, 13, or 14; Pin 15 can also work but the DHT must be disconnected during program upload)
- **GND**: GND

### LCD 1602 I2C Display Connection:
- **VCC**: 5.5V
- **GND**: GND
- **SDA**: A4 (Analog Pin 4)
- **SCL**: A5 (Analog Pin 5)

The circuit should resemble the following, with red wires indicating VCC and black wires indicating GND.

[Insert Circuit Diagram Image Here]

*Note: If your sensor is rapidly getting warm (only for 4 pin sensors), attach a 10K pull-up resistor joining VCC and the signal ends of the sensor.*

## Code Setup

### Libraries
Ensure you have the following libraries installed:

1. DHT Library ([Download Link](#)) - Use this library for interfacing with the DHT sensor.
2. LiquidCrystal_I2C Library - If you're using the Arduino Web Editor, no additional download is required as it's pre-included. If you're using software, this library might be pre-included, but if not, you can download it separately.

### Code Implementation
Here's how to implement the code:

1. Include the DHT library:
   ```cpp
   #include <DHT.h>
   ```

2. Define the sensor pin (e.g., if using pin 4):
   ```cpp
   #define DHTPIN 4
   ```

3. Determine the sensor type (e.g., for DHT11):
   ```cpp
   #define DHTTYPE DHT11
   ```

4. Instantiate the DHT object using the defined pin and type:
   ```cpp
   DHT dht(DHTPIN, DHTTYPE);
   ```

5. Include the LiquidCrystal_I2C library:
   ```cpp
   #include <LiquidCrystal_I2C.h>
   ```

6. Initialize the LCD object with the given parameters (address, columns, rows):
   ```cpp
   LiquidCrystal_I2C lcd(0x27, 16, 2);
   ```

*Note: The temperature is automatically in Celsius scale. If you prefer Fahrenheit, you can modify the code accordingly.*

## Recommendations
- For a hassle-free setup, consider using the Arduino Web Editor, which includes necessary libraries.
- If you're using software, ensure you have the required libraries installed. The LiquidCrystal_I2C library might be pre-included.

*Enjoy your project!*
