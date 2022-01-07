//* WRITTEN BY KAIO *
//-----------------------------------------------------------------------------------------------------------------------------------------------------
//!!! Requires libraries: ArduinoJoystickLibrary (MHeironimus) and Encoder (PaulStoffregen) !!!
//-----------------------------------------------------------------------------------------------------------------------------------------------------
//Use pins 0 and 1 to turn on the encoder, the remtant is configured as buttons.
//Use pin A0, A1 and A2 to connect the pedals, the relay is not configured.
//Load the code for your arduino and wait for it to load, open the serial monitor and make a complete turn on the steering wheel, the number shown will be the number of pulses.
//Change "5750" in "const int pulses = 5750;" to your encoder pulses.
//Change "3" in "const int turns = 3;" to change the amount of turns of the steering wheel (3 = 1080°, 2.5 = 900°).
//Load the code again and be happy! =D

const int pulses = 5750;
const int turns = 3;

#include "Joystick.h"
#include "Encoder.h"

Encoder myEnc(0, 1);

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
  12, 0,
  true, false, false,
  true, true, true,
  false, false,
  false, false, false);

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  Joystick.begin();
  Joystick.setXAxisRange(0, pulses*turns);
  Joystick.setRxAxisRange(0, 1023);
  Joystick.setRyAxisRange(0, 1023);
  Joystick.setRzAxisRange(0, 1023);
}

void loop() {
  delay(50);
  Serial.println("");
  Serial.print("Pulses:     ");
  Serial.println(myEnc.read());
  for(int i = 0; i <= 11; i++){
    Serial.println();}
  Joystick.setXAxis (myEnc.read()+((pulses*turns)/2));
  Joystick.setRxAxis (analogRead(A0));
  Joystick.setRyAxis (analogRead(A1));
  Joystick.setRzAxis (analogRead(A2));
  if (digitalRead(2) == LOW){Joystick.setButton(0, HIGH);}
  else {Joystick.setButton(0, LOW);}
  if (digitalRead(3) == LOW){Joystick.setButton(1, HIGH);}
  else {Joystick.setButton(1, LOW);}
  if (digitalRead(4) == LOW){Joystick.setButton(2, HIGH);}
  else {Joystick.setButton(2, LOW);}
  if (digitalRead(5) == LOW){Joystick.setButton(3, HIGH);}
  else {Joystick.setButton(3, LOW);}
  if (digitalRead(6) == LOW){Joystick.setButton(4, HIGH);}
  else {Joystick.setButton(4, LOW);}
  if (digitalRead(7) == LOW){Joystick.setButton(5, HIGH);}
  else {Joystick.setButton(5, LOW);}
  if (digitalRead(8) == LOW){Joystick.setButton(6, HIGH);}
  else {Joystick.setButton(6, LOW);}
  if (digitalRead(9) == LOW){Joystick.setButton(7, HIGH);}
  else {Joystick.setButton(7, LOW);}
  if (digitalRead(10) == LOW){Joystick.setButton(8, HIGH);}
  else {Joystick.setButton(8, LOW);}
  if (digitalRead(11) == LOW){Joystick.setButton(9, HIGH);}
  else {Joystick.setButton(9, LOW);}
  if (digitalRead(12) == LOW){Joystick.setButton(10, HIGH);}
  else {Joystick.setButton(10, LOW);}
  if (digitalRead(13) == LOW){Joystick.setButton(11, HIGH);}
  else {Joystick.setButton(11, LOW);}
}
