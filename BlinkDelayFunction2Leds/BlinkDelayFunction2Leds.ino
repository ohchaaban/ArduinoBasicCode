/*
  Name: Blink 2 leds with delay function.

  This example use the inefficient delay fuction to manage two leds.

  The green led supposed to turn on during 2 seconds and then turn off for an additional second,
  the red led supposed to turn on for just 6 seconds and then turn off for another 3 seconds,
  but the delay function doesn't know about time, it just makes the Arduino board freeze for an specific time.

  
  Go to my Github to find the Blink Multitasking example:
  https://github.com/ohchaaban/ArduinoLedExamples

  modified 04 Feb 2018
  by Omar Chaaban
  www.omarhchaaban.com
*/

const int greenLed = 2;         //Pin connected to the green led
const int redLed = 10;          //Pin connected to the red led


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital LedPin variable as an output.
  pinMode(greenLed, OUTPUT);
  digitalWrite(greenLed, HIGH); //The led is ON initialy.
  pinMode(redLed, OUTPUT);
  digitalWrite(redLed, HIGH); //The led is ON initialy.
}

// the loop function runs over and over again forever
void loop() {

  blinkDelay(greenLed, 2000, 1000); //Turn On the ledPin for two sec, turn off the led for one sec.
  blinkDelay(redLed, 6000, 3000); //Turn On the ledPin for six sec, turn off the led for three sec.
}

// BlinkDelay Fuction
void blinkDelay(int Pin, long timeHigh, long timeLow) {
  digitalWrite(Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(timeHigh);              // wait for a second
  digitalWrite(Pin, LOW);    // turn the LED off by making the voltage LOW
  delay(timeLow);
}

