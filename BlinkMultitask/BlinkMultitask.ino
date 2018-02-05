/*
  Name: Blink Multitask.
  
  Blink 2 leds using milli function.

  This example avoid the delay fuctions that freeze the Arduino board. It is now
  multitasking. 

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

  unsigned long currentMillis = millis();           //take the current time

  if (digitalRead(Pin) == LOW) {                            //ask for the actual led state

    if (currentMillis - previousMillis > timeLow) { //When the difference between the current time and the initial/previous time exceeds
      //the timeLow of the led, it turns it ON
      updateMillis(Pin, currentMillis); //Updating Milli Variables.
      digitalWrite(Pin, HIGH);
    }
  } else {
    if (currentMillis - previousMillis > timeHigh) { //When the difference between the current time and the initial/previous time exceeds
      //the timeHigh of the led, it turns it OFF
      updateMillis(Pin, currentMillis); //Updating Milli Variables.
      digitalWrite(Pin, LOW);
    }
  }

}

//Record the exact time when a led change its state.
void updateMillis(int Pin, long previousMillis) {

  switch (Pin) {    //Recognize the pin/Led used
    case greenLed:
      millisGreen = previousMillis;
      break;
    case redLed:
      millisRed = previousMillis;
      break;
  }

}

