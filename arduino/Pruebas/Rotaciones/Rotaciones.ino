/*
  State change detection (edge detection)

  Often, you don't need to know the state of a digital input all the time, but
  you just need to know when the input changes from one state to another.
  For example, you want to know when a button goes from OFF to ON. This is called
  state change detection, or edge detection.

  This example shows how to detect when a button or button changes from off to on
  and on to off.

  The circuit:
  - pushbutton attached to pin 2 from +5V
  - 10 kilohm resistor attached to pin 2 from ground
  - LED attached from pin 13 to ground through 220 ohm resistor (or use the
    built-in LED on most Arduino boards)

  created  27 Sep 2005
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection
*/

// this constant won't change:
const int  pin8 = 7;    // the pin that the pushbutton is attached to
const int pin7 = 8;       // the pin that the LED is attached to



void setup() {
  // initialize the button pin as a input:
  pinMode(pin8,  OUTPUT);
  // initialize the LED as an output:
  pinMode(pin7, OUTPUT);
  // initialize serial communication:
  digitalWrite(pin8,0);
  digitalWrite(pin7,0);
  Serial.begin(9600);
}


void loop() {
  digitalWrite(pin7,1);
  delay(2000);
  digitalWrite(pin7,0);
  delay(2000);
  digitalWrite(pin8,1);
  delay(2000);
  digitalWrite(pin8,0);
  delay(2000);
}
