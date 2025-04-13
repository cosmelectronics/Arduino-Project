# 🔴 Human Detection using PIR Sensor and Arduino UNO 🚀

Welcome to this smart motion detection project! This project demonstrates how to detect human presence using a **PIR Sensor** and display the status on a **16x2 LCD** via **I2C** module using **Arduino UNO**. It's a beginner-friendly DIY electronics project perfect for **home automation** and **security systems**.

## 🔹 Project Overview

This project uses a **Passive Infrared (PIR) Sensor** to detect motion and a **16x2 I2C LCD** to show real-time status messages:
- ✅ "Human Presence: Detected!" when motion is detected
- ✅ "Human Presence: Not Detected" when idle

A great way to visualize motion detection with minimal components and simple wiring!

---

## 🔧 Required Components

- 🟢 Arduino UNO  
- 🟢 PIR Motion Sensor  
- 🟢 16x2 LCD Display with I2C Module  
- 🟢 Jumper Wires  
- 🟢 Breadboard (optional)

---

## ⚡ Circuit Connections

### PIR Sensor:
- **OUT** → Digital Pin **D2**  
- **VCC** → **5V**  
- **GND** → **GND**

### I2C LCD:
- **SDA** → **A4**  
- **SCL** → **A5**  
- **VCC** → **5V**  
- **GND** → **GND**

> 💡 **Note:** The I2C address is usually `0x27` or `0x3F`. Adjust accordingly in the code.

---

## 🛠 Working Principle

The **PIR sensor** detects infrared radiation (heat) from a moving object, like a human. When motion is detected:
- Arduino receives a **HIGH** signal from the sensor.
- The LCD displays "**Detected!**"
- When no motion is sensed, it shows "**Not Detected**"

This allows for a real-time, non-contact human detection interface.

---

## 🎯 Use Cases

- ✅ Smart Home Monitoring 🏠  
- ✅ Motion-Activated Displays 📟  
- ✅ Entryway Security Systems 🚪  
- ✅ IoT-Based Automation Solutions 🔐  

---

## 🚀 Getting Started

1. Connect all components as per the wiring guide above.
2. Upload the provided Arduino code using the Arduino IDE.
3. Power up the Arduino board and observe the LCD display.
4. Move in front of the PIR sensor to trigger human detection.

---

## 👨‍💻 Project Author

**Prince Kushwaha**  
Designed with ❤️ under [COSM Electronics](https://github.com/cosmelectronics)

---

## 🌐 GitHub Repository

🔗 [Visit Project on GitHub]([https://github.com/cosmelectronics/](https://github.com/cosmelectronics/Arduino-Project/tree/main/Motion%20Detection))

---

## 📢 Don't forget to

⭐ Star the repo  
🍴 Fork it  
🐛 Report issues  
📬 Submit improvements  

---

## 🏷️ Tags & Hashtags

**Tags:** PIR Sensor, Arduino UNO, 16x2 LCD, I2C Module, Motion Detection, Human Detection, Smart Home, DIY Electronics, Arduino Projects, Home Automation

**Hashtags:**  
#pirsensor #arduinouno #16x2lcd #i2cmodule #motiondetection #humandetection #smarthome #arduinoprojects #diyelectronics #homeautomation #securitysystem #lcdproject #iot #motionsensor #embeddedsystems #microcontroller #cosmelectronics #princekushwaha #automation #electronicprojects #visualfeedback #prototyping #realtimedisplay #arduinoide #opensource

