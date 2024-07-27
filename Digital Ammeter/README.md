# Arduino Current Measurement Project

This project is designed to measure current using an Arduino Uno, a 16x2 LCD with an I2C module, and other basic electronic components. The current value is calculated and displayed on the LCD as well as printed to the Serial Monitor.

## Components Required

- **Arduino Uno**
- **Resistor 10Ω**
- **LCD 16x2** with I2C module
- **Red LED**
- **Breadboard**
- **Jumper cables**

## How It Works

1. **Initialize Components**: The LCD and Serial communication are initialized in the `setup` function.
2. **Read Analog Values**: The analog values from two analog pins (A0 and A1) are read.
3. **Calculate Current**: The difference between the two analog values is calculated, converted to voltage, and then the current value is determined using the appropriate formula.
4. **Display Output**: The current value is displayed on the LCD and printed to the Serial Monitor.
5. **Repeat**: The process is repeated every second.

## Circuit Diagram

![Circuit Diagram]([path_to_circuit_diagram_image](https://github.com/cosmelectronics/Arduino-Project/blob/main/Digital%20Ammeter/Circuit%20Diagram.png )

## Code

The code for this project is available in the `main.ino` file. Below is a brief overview of the code structure:

1. **Include Libraries**: The necessary libraries for the LCD and I2C communication are included.
2. **Initialize LCD**: The LCD is initialized with its I2C address.
3. **Setup Function**: Serial communication and LCD initialization are performed.
4. **Loop Function**: The main logic for reading values, calculating current, and displaying the result is implemented.

For detailed code, please refer to the `digital_ammeter.ino` file in this repository.

---

This code is designed by Prince Kushwaha from COSM Electronics.
