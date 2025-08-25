const int ledpin1=13;
const int ledpin2=12;

unsigned long previous_millis1=0;
unsigned long previous_millis2=0;

const unsigned long interval1 = 1000;
const unsigned long interval2 = 500;

int ledstate1= LOW;
int ledstate2= LOW;

void setup(){

  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
}
void loop(){

  unsigned long current_millis= millis();

  if(current_millis - previous_millis1>=interval1){
    
    if(ledstate1 == LOW){
      ledstate1 = HIGH;
    }
    else {
      ledstate1 = LOW;
    }

    previous_millis1= current_millis;
    digitalWrite(ledpin1,ledstate1);
    }
    
    if(current_millis - previous_millis2>=interval2){

    
    if(ledstate2 == LOW){
      ledstate2 = HIGH;
    }
    else {
      ledstate2 = LOW;
    }

    previous_millis2= current_millis;


    digitalWrite(ledpin2,ledstate2);
    }

  }