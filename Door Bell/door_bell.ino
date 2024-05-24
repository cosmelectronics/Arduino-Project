#include <pitches.h>

// Define the notes
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_D6  1175
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_G6  1568
#define NOTE_A6  1760
#define NOTE_B6  1976
#define NOTE_C7  2093

// Define the pins
const int buttonPin = 2; // the pin the pushbutton is connected to
const int buzzerPin = 3; // the pin the buzzer is connected to

// Define the melody
int melody[] = {
  NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5,
  NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5,
  NOTE_G4, NOTE_E5, NOTE_G4, NOTE_E5, NOTE_G4, NOTE_E5, NOTE_G4, NOTE_E5,
  NOTE_G4, NOTE_E5, NOTE_G4, NOTE_E5, NOTE_G4, NOTE_E5, NOTE_G4, NOTE_E5
};

// Define the note durations
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4
};

// Variables
bool buttonState = 0;    // current state of the button
bool lastButtonState = 0; // previous state of the button

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // initialize the buzzer pin as an output:
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the button is pressed and the previous state was not pressed
  if (buttonState == HIGH && lastButtonState == LOW) {
    // play the melody
    playMelody();
  }

  // update the previous button state
  lastButtonState = buttonState;
}

// Function to play the melody
void playMelody() {
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    // Calculate the note duration
    int noteDuration = 1000 / noteDurations[i];
    // Play the tone
    tone(buzzerPin, melody[i], noteDuration);
    // Delay between notes
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // Stop the tone
    noTone(buzzerPin);
    // Delay to distinguish between notes
    delay(50);
  }
}
