# Smart Traffic Management System

This project is a **Smart Traffic Management System** designed by Prince Kushwaha from COSM Electronics. The system uses an Arduino to control traffic lights and an LCD to display the current signal and remaining time.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Smart Traffic Management System aims to automate traffic light control, making it more efficient and reducing traffic congestion. This project utilizes an Arduino, LEDs to simulate traffic lights, and an LCD for real-time display of traffic signals.

## Features

- **Automated Traffic Light Control**: Automatically cycles through green, yellow, and red lights with specified durations.
- **LCD Display**: Shows the current signal (GO, SLOW, STOP) and the remaining time for each signal.
- **Customizable Timings**: Easily adjust the durations for green, yellow, and red lights by modifying the code.

## Components

To build this project, you will need the following components:

- Arduino Board
- LiquidCrystal I2C LCD (16x2)
- LEDs (Red, Yellow, Green)
- Resistors
- Breadboard and Jumper Wires

## Circuit Diagram

Connect the components as follows:

- **Red LED**: Connect to pin 2 on the Arduino through a resistor.
- **Yellow LED**: Connect to pin 3 on the Arduino through a resistor.
- **Green LED**: Connect to pin 4 on the Arduino through a resistor.
- **LCD**: Connect the SDA and SCL pins to the respective pins on the Arduino (usually A4 and A5 on the Uno).

## Installation

1. **Clone the Repository**: Clone this repository to your local machine using `git clone https://github.com/yourusername/smart-traffic-management-system.git`.
2. **Upload the Code**: Open the `.ino` file in the Arduino IDE and upload it to your Arduino board.
3. **Wire the Components**: Connect all components as per the circuit diagram.
4. **Power the System**: Power up your Arduino board to start the traffic management system.

## Usage

Once the system is powered on, the traffic lights will cycle through green, yellow, and red signals. The LCD will display the current signal and the remaining time for each phase. Adjust the timing variables in the code if you need different durations for each light.

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.
