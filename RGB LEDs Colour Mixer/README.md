# RGB LED Color Mixer

Have fun with colors by building an RGB LED color mixer. RGB LEDs can emit red, green, and blue light, which can be combined to create a wide range of colors. By controlling the intensity of each color using PWM (Pulse Width Modulation), you'll be able to mix and create various hues.

## Components Required

- Arduino board (e.g., Arduino Uno)
- Common anode RGB LED
- 3 x 220-ohm resistors
- Breadboard
- Jumper wires
- 3 potentiometers (optional for manual control)

## Circuit Diagram

### Connecting RGB LED

1. Common anode of RGB LED → 5V (VCC)
2. Red pin of RGB LED → 220-ohm resistor → Digital PWM pin 9
3. Green pin of RGB LED → 220-ohm resistor → Digital PWM pin 10
4. Blue pin of RGB LED → 220-ohm resistor → Digital PWM pin 11

### Connecting Potentiometers (Optional for Manual Control)

1. Connect one terminal of each potentiometer to 5V.
2. Connect the opposite terminal to Ground (GND).
3. Connect the middle terminal of each potentiometer to Analog pins A0, A1, and A2 respectively.

## Setup

1. Assemble the components as per the circuit diagram.
2. Upload the Arduino code to your Arduino board.

## Usage

1. Once the code is uploaded, the RGB LED should start reacting to the potentiometer adjustments.
2. By adjusting the potentiometers, you can mix different colors by changing the intensity of red, green, and blue lights.

## Debugging

- The code includes serial print statements to output the PWM values of the red, green, and blue channels to the Serial Monitor. This helps in debugging and understanding the color mixing process.

## Author

This Code is Designed by Prince Kushwaha from COSM Electronics.
