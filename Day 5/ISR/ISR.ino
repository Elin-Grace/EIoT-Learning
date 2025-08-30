// Pin setup
const int buttonPin = 2;     // Must be an interrupt-capable pin (Uno: 2 or 3)
const int ledPin = 13;       // Built-in LED

// Shared variables
volatile bool ledStateNeedsUpdate = false; // Flag set inside ISR
bool ledState = LOW; // LED state (normal variable, toggled in loop)

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Button wired to GND
  pinMode(ledPin, OUTPUT);

  // Attach interrupt: trigger on button press (falling edge)
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressedISR, FALLING);
}

void loop() {
  // Check if ISR flagged an update
  if (ledStateNeedsUpdate) {
    // Critical section: briefly disable interrupts while clearing the flag
    noInterrupts();
    ledStateNeedsUpdate = false;
    interrupts();

    // Toggle LED
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}

// Interrupt Service Routine (ISR)
void buttonPressedISR() {
  ledStateNeedsUpdate = true; // Just set the flag
}
