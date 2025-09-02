// Step 1:Defining the states
enum State{
  STATE_OFF,
  STATE_SOLID_ON,
  STATE_BLINKING
};

//Step 2: tracking the current state
State currentState = STATE_OFF;
//Step 3: pin setup
const int ledPin =13;
const int buttonPin =2; //led and button press
bool buttonState =LOW;
bool lastButtonState = LOW;// for debouncing
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay =50;//to avoid noisy button press



void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // --- Step 4: Handle button with debounce ---
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) { // Button pressed
        // Change state on press
        if (currentState == STATE_OFF) {
          currentState = STATE_SOLID_ON;
        } else if (currentState == STATE_SOLID_ON) {
          currentState = STATE_BLINKING;
        } else if (currentState == STATE_BLINKING) {
          currentState = STATE_OFF;
        }
      }
    }
  }
  lastButtonState = reading;

  // --- Step 5: Do action based on state ---
  switch (currentState) {
    case STATE_OFF:
      Serial.println("STATE: OFF");
      digitalWrite(ledPin, LOW);
      break;

    case STATE_SOLID_ON:
      Serial.println("STATE: SOLID ON");
      digitalWrite(ledPin, HIGH);
      break;

    case STATE_BLINKING:
      Serial.println("STATE: BLINKING");
      digitalWrite(ledPin, millis() % 500 < 250 ? HIGH : LOW); // Blink
      break;
  }
}

