const int buttonPin=2;
const int LEDPin=13;
int buttonState;            
int lastButtonState = HIGH; 
int ledState = LOW;         

unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;    // 50ms debounce window

void setup() {
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(LEDPin,OUTPUT);
}

void loop(){
 int reading = digitalRead(buttonPin);

  // If button reading changed, reset the debounce timer
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  // Only accept the reading if it’s stable for > debounceDelay
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If state actually changed
    if (reading != buttonState) {
      buttonState = reading;

      // Toggle LED only when button is pressed (LOW, since INPUT_PULLUP)
      if (buttonState == LOW) {
        ledState = !ledState;
      }
    }
  }

  digitalWrite(LEDPin, ledState);
  lastButtonState = reading;
}
