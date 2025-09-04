int ldr=A0;
int ldrValue=0;
int led=9;
int threshold=300;//my bright is 450,and dark is 150,hence average 300 
void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValue=analogRead(ldr);
  Serial.println(ldrValue);
  if (ldrValue<threshold){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  delay(100);
  }

