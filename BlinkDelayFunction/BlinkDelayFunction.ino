/*
  Blink with delay function.   
  
  modified 04 Feb 2018
  by Omar Chaaban
 */

const int LedPin = 7;         //Pin connected to the led


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital LedPin variable as an output.
  pinMode(LedPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
blinkDelay(LedPin, 2000,1000); //Turn On the ledPin for two sec, turn off the led for one sec.
}

// BlinkDelay Fuction
void blinkDelay(int Pin, long timeHigh, long timeLow){
  digitalWrite(Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(timeHigh);              // wait for a second
  digitalWrite(Pin, LOW);    // turn the LED off by making the voltage LOW
  delay(timeLow);
}

