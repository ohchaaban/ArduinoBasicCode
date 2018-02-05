/*
  Blink with millis function.   
  
  modified 04 Feb 2018
  by Omar Chaaban
 */

const int LedPin = 7;           //Pin connected to the led
long previousMillis = 0;        // will store last time LED was updated


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital LedPin variable as an output.
  pinMode(LedPin, OUTPUT);
  digitalWrite(LedPin,ledState);
}

// the loop function runs over and over again forever
void loop() {
blinkMillis(LedPin, 2000,1000); //Turn On the ledPin for two sec, turn off the led for one sec.
}

//BlinkMillis Function
void blinkMillis(int Pin, long timeHigh, long timeLow){

  unsigned long currentMillis = millis();           //take the current time
  if (ledState == LOW) {                            //ask for the actual led state
    
    if(currentMillis - previousMillis > timeLow) {  //When the difference between the current time and the initial/previous time exceeds
            previousMillis = currentMillis;         //the timeLow of the led, it turns it ON
            ledState = HIGH;
              digitalWrite(LedPin,ledState);
    }
} else {
    if(currentMillis - previousMillis > timeHigh) { //When the difference between the current time and the initial/previous time exceeds
          previousMillis = currentMillis;           //the timeHigh of the led, it turns it OFF
          ledState = LOW;
          digitalWrite(LedPin,ledState);
    } 
}

}
