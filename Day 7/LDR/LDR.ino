int ldr=A0;
int ldrValue=0;

void setup() {
  Serial.begin(9600); // start serial monitor
}

void loop() {
  ldrValue=analogRead(ldr);
  Serial.println(ldrValue);
  delay(50);
  
}
