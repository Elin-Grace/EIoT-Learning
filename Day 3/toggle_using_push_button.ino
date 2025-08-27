const int buttonPin=2; // button connected to pin 2
const int ledPin=13;   // LED connected to pin 13
bool LedState=LOW;  // current led state
int lastButtonState=LOW; // stores last button reading

void setup() {
pinMode(buttonPin,INPUT_PULLUP) ; // button with input pullup(input pullup has inverse logic)
pinMode(ledPin,OUTPUT);  
// put your setup code here, to run once:

}

void loop() {
  int buttonState= digitalRead(buttonPin);
  // detect button press transition (HIGH → LOW because of pull-up)
  if (buttonState==LOW && lastButtonState==HIGH) //Last state	Current state	Meaning
  { LedState=!LedState;                         //HIGH	LOW	Button just pressed 
    digitalWrite(ledPin,LedState);              //LOW	LOW	Button held down
    delay(200); // done to prevent debounce(multiple toggle at single press)
  }                                             //LOW	HIGH	Button released
                                                //HIGH	HIGH	Button not pressed
  lastButtonState=buttonState; //Updating buttonstate                                            
                                               
    
}
