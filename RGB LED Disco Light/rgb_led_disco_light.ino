// This Code is Designed by Prince Kushwaha
// Define RGB LED pins
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Define push button pin
const int buttonPin = 2;

// Define variables for button state
int buttonState = 0;
int lastButtonState = 0;

// Define variables for disco mode control
int discoMode = 0;
unsigned long previousMillis = 0;
const long interval = 100; // milliseconds

void setup() {
  // Initialize RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT);

  // Initialize push button pin as input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Read the state of the push button
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      discoMode = (discoMode + 1) % 4; // Change disco mode when button is pressed
    }
    delay(50); // Debouncing delay
  }
  lastButtonState = buttonState;

  // Perform actions based on the current disco mode
  switch (discoMode) {
    case 0: // Static color
      setColor(255, 0, 0); // Red
      break;
    case 1: // Color fading
      colorFading();
      break;
    case 2: // Blinking
      blinking();
      break;
    case 3: // Random colors
      randomColors();
      break;
  }
}

// Function to set RGB color
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

// Function for color fading effect
void colorFading() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    static int hue = 0;
    hue = (hue + 1) % 256;
    int saturation = 255;
    int brightness = 255;
    int r, g, b;
    hsvToRgb(hue, saturation, brightness, &r, &g, &b);
    setColor(r, g, b);
  }
}

// Function for blinking effect
void blinking() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    static bool state = false;
    state = !state;
    if (state) {
      setColor(255, 255, 255); // White
    } else {
      setColor(0, 0, 0); // Off
    }
  }
}

// Function for generating random colors
void randomColors() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    int red = random(0, 256);
    int green = random(0, 256);
    int blue = random(0, 256);
    setColor(red, green, blue);
  }
}

// Function to convert HSV to RGB
void hsvToRgb(int h, int s, int v, int *r, int *g, int *b) {
  int i;
  float f, p, q, t;
  if (s == 0) {
    // Achromatic (grey)
    *r = *g = *b = v;
    return;
  }
  h /= 60; // sector 0 to 5
  i = floor(h);
  f = h - i; // factorial part of h
  p = v * (1 - s);
  q = v * (1 - s * f);
  t = v * (1 - s * (1 - f));
  switch (i) {
    case 0:
      *r = v;
      *g = t;
      *b = p;
      break;
    case 1:
      *r = q;
      *g = v;
      *b = p;
      break;
    case 2:
      *r = p;
      *g = v;
      *b = t;
      break;
    case 3:
      *r = p;
      *g = q;
      *b = v;
      break;
    case 4:
      *r = t;
      *g = p;
      *b = v;
      break;
    default: // case 5:
      *r = v;
      *g = p;
      *b = q;
      break;
  }
}
