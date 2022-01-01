//* WRITTEN BY KAIO *
//-----------------------------------------------------------------------------------------------------------------------------------------------------
//!!! Requires libraries: Arduino Joystick Library (MHeironimus) and Encoder (PaulStoffregen) !!!
//-----------------------------------------------------------------------------------------------------------------------------------------------------
//Use pins 0 and 1 to turn on the encoder, the remtant is configured as buttons.
//Use pin A0, A1 and A2 to connect the pedals, the relay is not configured.
//Load the code for your arduino and wait for it to load, open the serial monitor and make a complete turn on the steering wheel, the number shown will be the number of pulses.
//Change "5750" in "const int pulses = 5750;" to your encoder pulses.
//Change "3" in "const int pulseLimit = 3;" to change the amount of turns of the steering wheel (3 = 1080º, 2.5 = 900º).
//Load the code again and be happy! =D

const int pulses = 5750;
const int pulseLimit = 3;

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
  Joystick.setXAxisRange(0, pulses*pulseLimit);
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
  Joystick.setXAxis (myEnc.read()+((pulses*pulseLimit)/2));
  Joystick.setRxAxis (analogRead(A0));
  Joystick.setRyAxis (analogRead(A1));
  Joystick.setRzAxis (analogRead(A2));
  if (digitalRead(2) == HIGH){Joystick.setButton(0, LOW);}
  else {Joystick.setButton(0, HIGH);}
  if (digitalRead(3) == HIGH){Joystick.setButton(1, LOW);}
  else {Joystick.setButton(1, HIGH);}
  if (digitalRead(4) == HIGH){Joystick.setButton(2, LOW);}
  else {Joystick.setButton(2, HIGH);}
  if (digitalRead(5) == HIGH){Joystick.setButton(3, LOW);}
  else {Joystick.setButton(3, HIGH);}
  if (digitalRead(6) == HIGH){Joystick.setButton(4, LOW);}
  else {Joystick.setButton(4, HIGH);}
  if (digitalRead(7) == HIGH){Joystick.setButton(5, LOW);}
  else {Joystick.setButton(5, HIGH);}
  if (digitalRead(8) == HIGH){Joystick.setButton(6, LOW);}
  else {Joystick.setButton(6, HIGH);}
  if (digitalRead(9) == HIGH){Joystick.setButton(7, LOW);}
  else {Joystick.setButton(7, HIGH);}
  if (digitalRead(10) == HIGH){Joystick.setButton(8, LOW);}
  else {Joystick.setButton(8, HIGH);}
  if (digitalRead(11) == HIGH){Joystick.setButton(9, LOW);}
  else {Joystick.setButton(9, HIGH);}
  if (digitalRead(12) == HIGH){Joystick.setButton(10, LOW);}
  else {Joystick.setButton(10, HIGH);}
  if (digitalRead(13) == HIGH){Joystick.setButton(11, LOW);}
  else {Joystick.setButton(11, HIGH);}
}
