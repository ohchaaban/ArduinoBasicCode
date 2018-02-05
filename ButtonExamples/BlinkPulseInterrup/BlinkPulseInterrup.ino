/*
  Name: BlinkPulseInterrup.

  Otherwise the BlinkButtonInterrup, at this time we are able to send a pulse 

  Now we Blink the green and with a pushbutton using the Attach Interrup function.
  As you see, there is nothing inside void loop function because the Arduino do not
  need to read any input over and over, it just needs to wait to be interrupted to
  call the the blink functions in this case.

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
volatile byte state = LOW;    

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital LedPin variables as outputs and both start On.
  pinMode(redLed, OUTPUT);
  digitalWrite(redLed, HIGH);
  pinMode(greenLed, OUTPUT);
  digitalWrite(greenLed, HIGH);
 
  pinMode(interruptPin, INPUT_PULLUP);
  //when an interrup is active by a oltage CHANGE, it call the BLINK function inmediately.
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

// the loop function runs over and over again forever
void loop() {

  if  (state == HIGH){
  blinkMillis(greenLed, 2000, 1000, millisGreen); //Turn On the ledPin for two sec, turn off the led for one sec.
  blinkMillis(redLed, 6000, 3000, millisRed); //Turn On the ledPin for six sec, turn off the led for 3 sec.
//  }else{
//
//  if ()  
 
  
  }
 
}

//This function is called when exist an interrup.
//It's change the state of the pin/led. 
void blink() {
  state = !state;
  millisGreen = millis();
  millisRed = millis();  

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



