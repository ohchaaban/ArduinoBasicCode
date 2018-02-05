/*
  Name: Blink Multitask.

  Blink 2 leds using millis function.

  This example avoid the delay fuctions that freeze the Arduino board and It's a
  multitasking board now. This is a great way to blink leds, read sensors and 
  do more stuffs at the same time, being precise and accurate.  

    Go to my Github to get more code examples:
  https://github.com/ohchaaban/ArduinoLedExamples

  Created on 04 Feb 2018
  by Omar Chaaban
  www.omarchaaban.com
*/

const int greenLed = 2;           //Pin connected to the green led
long millisGreen = 0;        // will store last time 1st LED was updated

const int redLed = 10;           //Pin connected to the red led
long millisRed = 0;        // will store last time 2nd LED was updated



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital LedPin variables as outputs and both start On.
  pinMode(redLed, OUTPUT);
  digitalWrite(redLed, HIGH);
  pinMode(greenLed, OUTPUT);
  digitalWrite(greenLed, HIGH);
}

// the loop function runs over and over again forever
void loop() {
  blinkMillis(greenLed, 2000, 1000, millisGreen); //Turn On the ledPin for two sec, turn off the led for one sec.
  blinkMillis(redLed, 6000, 3000, millisRed); //Turn On the ledPin for six sec, turn off the led for 3 sec.
}

//BlinkMillis Function
void blinkMillis(int Pin, long timeHigh, long timeLow, long previousMillis) {

  unsigned long currentMillis = millis();
  //take the current time

  if (digitalRead(Pin) == LOW) {
    //ask for the actual led/pin state

    //Check if it's time to change the led's state
    // between the current time and last time you blinked the LED is bigger than
    // the interval at which you want to blink the LED.
    
    if (currentMillis - previousMillis > timeLow) { //
      updateMillis(Pin, currentMillis); //Updating Milli Variables.
      digitalWrite(Pin, HIGH);
    }
  } else {
    if (currentMillis - previousMillis > timeHigh) {
      updateMillis(Pin, currentMillis); //Updating Milli Variables.
      digitalWrite(Pin, LOW);
    }
  }

}

//Record the exact time when a specific led/pin change its state.
void updateMillis(int Pin, long previousMillis) {

  switch (Pin) {    
    case greenLed: 
      millisGreen = previousMillis;
      break;
    case redLed:
      millisRed = previousMillis;
      break;
  }

}

