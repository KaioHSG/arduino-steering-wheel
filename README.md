# ArduinoSteeringWheel

* WRITTEN BY KAIO

!!! Requires libraries: Arduino Joystick Library (MHeironimus) and Encoder (PaulStoffregen) !!!

Use pins 0 and 1 to turn on the encoder, the remtant is configured as buttons.
Use pin A0, A1 and A2 to connect the pedals, the relay is not configured.
Load the code for your arduino and wait for it to load, open the serial monitor and make a complete turn on the steering wheel, the number shown will be the number of pulses.
Change "5750" in "const int pulses = 5750;" to your encoder pulses.
Change "3" in "const int pulseLimit = 3;" to change the amount of turns of the steering wheel (3 = 1080º, 2.5 = 900º).
Load the code again and be happy! =D
