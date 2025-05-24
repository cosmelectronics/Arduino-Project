# L298N Motor Driver Control with Arduino UNO

This project demonstrates how to interface a **single DC motor** with the **L298N Motor Driver Module** using an **Arduino UNO**. The motor rotates in both **clockwise** and **anticlockwise** directions automatically with timed delays.

## 🚀 Features

- Control of one DC motor using L298N.
- Clockwise and anticlockwise rotation.
- Adjustable speed via PWM signal.
- Simple and beginner-friendly Arduino implementation.

## 🧰 Components Required

- Arduino UNO
- L298N Motor Driver Module
- DC Motor (1 unit)
- Jumper Wires
- Power Supply (external for motor)

## 🔌 Wiring Instructions

| L298N Pin | Arduino Pin |
|-----------|-------------|
| IN1       | 8           |
| IN2       | 9           |
| ENA       | 10 (PWM)    |
| OUT1/OUT2 | Motor       |
| 5V/GND    | Power Lines |

> Ensure you connect a proper power source for the motor. Avoid powering the motor directly from the Arduino.


## 🧑‍💻 Author

**Prince Kushwaha**  
Designed under **COSM Electronics**

---

Feel free to customize the motor speed and delay timings in the Arduino code to suit your project requirements.


