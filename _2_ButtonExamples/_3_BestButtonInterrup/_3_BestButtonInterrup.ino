/*
  Name: BlinkButtonInterrup.

  Now I Blink the green and with a pushbutton using the Attach Interrup function.
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
const int redLed = 10;           //Pin connected to the red led

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

 
}

//This function is called when exist an interrup.
//It's change the state of the pin/led. 
void blink() {
  state = !state;
  digitalWrite(redLed, state);
  digitalWrite(greenLed, state);
}



