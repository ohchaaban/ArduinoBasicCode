/*
  Name: BlinkPulseInterrup.

  Otherwise the BlinkButtonInterrup, at this time we are able to send a pulse

  Now I modified the BlinkButtonInterrup Sketch, at this time I use the button
  to handle both leds. You can see this example like a process.

  Once we press the button, both leds blink together and they stop only when
  ends when the red led complete it's interval (6 secs ON and 3 secs OFF).
  That's the process, the green led will blinks 3 times and the red one just once.

  To do this I overwitte the blink fuction, adding new variables. Also I created a
  new fuction called checkPeriod() to know when the red led completed its blinking
  and stop the process.

  I still use the millis fuction because I don't want to frezee the Arduino. So if I
  need to do more things the microcontroller will do it with no problem.

  Now you can build your code with the certain your device will respond to a event
  inmediately!

  The arduino UNO only have 2 interrup pins (2,3), There are other boards with more Interrup pins though.
  Also, There are different configurations for this Attach Interrup funtion.
  For more information check the references.


  Go to my Github to get more code examples:
  https://github.com/ohchaaban/ArduinoLedExamples

  Modified on 05 Feb 2018
  by Omar Chaaban
  www.omarchaaban.com

  References:
  https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
*/

const int greenLed = 2;           //Pin connected to the green led
long millisGreen = 0;        // will store last time 1st LED was updated

const int redLed = 10;           //Pin connected to the red led
long millisRed = 0;        // will store last time 2nd LED was updated

const byte interruptPin = 3;     //Pin connected to the pushbutton
//volatile byte state = LOW;
int intervalCounter = 0;         //Count the times when the longest pulse change (The red led's pulse), then we finish the leds' blink.
boolean flag = false;            //When the button is pressed, the flag lets blink running until the red led ends its interval.

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital LedPin variables as outputs and both start On.
  pinMode(redLed, OUTPUT);
  digitalWrite(redLed, HIGH);
  pinMode(greenLed, OUTPUT);
  digitalWrite(greenLed, HIGH);
  pinMode(5, OUTPUT);

  pinMode(interruptPin, INPUT_PULLUP);
  //when an interrup is active by a oltage CHANGE, it call the BLINK function inmediately.
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

// the loop function runs over and over again forever
void loop() {

  if  (flag == true) {
    blinkMillis(greenLed, 2000, 1000, millisGreen); //Turn On the ledPin for two sec, turn off the led for one sec.
    blinkMillis(redLed, 6000, 3000, millisRed); //Turn On the ledPin for six sec, turn off the led for 3 sec.
  }

}


//This function is called when exist an interrup.
//It's change the state of the pin/led.
void blink() {
  //  state = !state;
  if (flag == false){
  millisGreen = millis(); //set the time when the button was activated
  millisRed = millis();   // as the initial time of the blink
  resetTimers();
  intervalCounter = 0;
  flag  = true; // the flag lets blink running until the red led ends its interval
  }
  
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
      /*As the red led has the largest period,
        we increment the counter when a the led's
        state change 2 times. It means that the
        the period is completed to stop the blink,
        changing the flag to false.
      */
      millisRed = previousMillis;
      flag = !checkPeriod();  //Wait until the red led complete it's period to stop the blink.
      //When checkPeriod is True, the flag turns false and viceversa.
      break;
  }

}

boolean checkPeriod() {
  //return true when the period is completed.
  intervalCounter ++;
  if (intervalCounter > 1) {\ 
  //I let the leds ON, as they were at first. 
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, HIGH);
    return true; //stop the blink
  }
  return false; // do not stop the blink
}

///Reset simulation's timers

void resetTimers(){
  digitalWrite(5, LOW);
  delay(1); 
  digitalWrite(5, HIGH);
  delay(1);
  digitalWrite(5, LOW);

  /*
  Eventhough I am using the delay function,
  A) it's for a very short of time, one microsecond.
  B) The leds used the millis funtions before I call this function,
  so the leds will count this microsecond.
  C)This fuction is NOT called in the void loop. Avoid use delays
  and call functions with delays in them always in void loop.

  NOTE: One microsecond works in a simulation, probably this value have 
  to be bigger in the real life though, maybe 50ms.
   */
  
}



