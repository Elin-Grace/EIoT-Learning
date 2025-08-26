const int buttonPin = 2;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // activate pull-up resistor
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    Serial.println("Button PRESSED");
  } else {
    Serial.println("Button NOT pressed");
  }

  delay(200); // slow down serial printing
}