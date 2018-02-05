/*
  Blink with delay function.   
  
  Blink Example modified 04 Feb 2018
  by Omar Chaaban
 */

const int LedPin = 7;         //Pin connected to the led
const long delayPin = 1000;   //Delay's led in milliseconds

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital LedPin variable as an output.
  pinMode(LedPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(LedPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayPin);              // wait for a second
  digitalWrite(LedPin, LOW);    // turn the LED off by making the voltage LOW
  delay(delayPin);
  
}
