 /*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald

  This example is inefficient to do more than blink a led. The Arduino Board just freeze during the delay function,
  if you try to turn 2 leds with different times you'll fail. The worst thing you can use is the delay function on
  your code.
  
  Go to my Github to find the Blink Multitasking example:
  https://github.com/ohchaaban/ArduinoLedExamples

  modified 04 Feb 2018
  by Omar Chaaban
  www.omarhchaaban.com
*/

const int greenLed = 2;         //Pin connected to the green led

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital LedPin variable as an output.
  pinMode(greenLed, OUTPUT);
  digitalWrite(greenLed, HIGH); //The led is ON initialy.
}

// the loop function runs over and over again forever
void loop() {

  blinkDelay(greenLed, 2000, 1000); //Turn On the ledPin for two sec, turn off the led for one sec.
}

// BlinkDelay Fuction
void blinkDelay(int Pin, long timeHigh, long timeLow) {
  digitalWrite(Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(timeHigh);              // wait for a second
  digitalWrite(Pin, LOW);    // turn the LED off by making the voltage LOW
  delay(timeLow);
}
