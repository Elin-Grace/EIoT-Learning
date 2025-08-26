const int ledPin = 13;       // Built-in LED pin
unsigned long previousMillis = 0;
const long interval = 1000;  // 1 second
int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);   // Start serial communication at 9600 baud
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Toggle LED state
    ledState = !ledState;
    digitalWrite(ledPin, ledState);

    // Print info
    Serial.print("LED Toggled!  Time: ");
    Serial.println(currentMillis);
  }
}