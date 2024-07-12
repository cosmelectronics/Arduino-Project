# Arduino Music Player

Welcome to the Arduino Music Player project! This project allows you to play different tunes using an Arduino board and a piezo buzzer or speaker.

## Features

- **Multiple Tunes**: Play different tunes including "Happy Birthday", "Nokia Tune", and "Merry Christmas".
- **Customizable**: Easily change the tempo and the pin to which the buzzer or speaker is connected.
- **Serial Interface**: Use the serial monitor to select and play different tunes.

## Getting Started

### Hardware Requirements

- Arduino board (e.g., Uno, Nano)
- Piezo buzzer or speaker
- Jumper wires

### Software Requirements

- Arduino IDE

### Setup Instructions

1. **Connect the Buzzer/Speaker**: 
   - Connect the positive leg of the piezo buzzer or speaker to pin 11 on the Arduino.
   - Connect the negative leg to the ground (GND) pin on the Arduino.

2. **Upload the Code**:
   - Open the Arduino IDE.
   - Copy and paste the provided code into the IDE.
   - Select the correct board and port from the Tools menu.
   - Click the upload button to upload the code to the Arduino.

3. **Open the Serial Monitor**:
   - Open the serial monitor from the Tools menu.
   - Set the baud rate to 9600.

### Using the Arduino Music Player

Once the setup is complete and the code is uploaded:

1. Open the serial monitor.
2. Follow the on-screen instructions to select a tune:
   - Press `a` to play the "Happy Birthday" tune.
   - Press `b` to play the "Nokia Tune".
   - Press `c` to play the "Merry Christmas" tune.

### Customization

- **Change the Pin**: To use a different pin for the buzzer, modify the `buzzer` variable in the code.
- **Adjust the Tempo**: To change the tempo of the tunes, modify the `tempo1`, `tempo2`, and `tempo3` variables in the code.

## Contribution

Feel free to fork the repository and submit pull requests with improvements or new features. Contributions are welcome!

## Acknowledgements

This code is designed by Prince Kushwaha from COSM Electronics.

Happy coding and enjoy the music!
