/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 2 and 10,
  when pressing a pushbutton attached to pin 3.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Button
  -----------------------------------------------------------------------------

  The code seems to work fine, it's getting complicate to code though. First of all, 
  you are wasting a piece of time reading an output in every loop. Otherwise this kind 
  of code will take more lines. However, this is acceptable in some cases but I recommmend
  use the attach Interrup function. it's a beautiful piece of cake code. 

   Go to my Github to get the best way to code this with examples:
  https://github.com/ohchaaban/ArduinoLedExamples
  
  Modified on 05 Feb 2018
  by Omar Chaaban
  www.omarchaaban.com

*/


const int greenLed = 2;           //Pin connected to the green led
const int redLed = 10;           //Pin connected to the red led

const int buttonPin = 3;        //Pin connected to the pushbutton
int buttonState = LOW;         // variable for reading the pushbutton status

void setup() {
  // initialize digital LedPin variables as outputs and both start On.
  pinMode(redLed, OUTPUT);
  digitalWrite(redLed, HIGH);
  pinMode(greenLed, OUTPUT);
  digitalWrite(greenLed, HIGH);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  readPinButton();
}

void readPinButton() {
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, HIGH);
  } else {
    // turn LED off:
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
  }
}

