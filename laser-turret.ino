//===========================================
// LASER SERVO V1.0
// A LASER TURRET THAT CAN GO LEFT TO RIGHT,
// UP TO DOWN WITH THE HELP OF SERVOS
//===========================================
// PINOUT DIAGRAM:
//===========================================
// ITEM                 PIN NUMBER
// SERVO (LEFT RIGHT)   7
// SERVO (UP DOWN)      8
// LASER                (NORMAL GROUND AND 5V)
// POT (LEFT TO RIGHT)  A0
// POT (UP TO DOWN)     A1
//===========================================
// NABIL RIDHWANSHAH (C) 2019

// Include the Servo library
#include <Servo.h>

// Define pins for the potentiometer that controls the servo (lr means left right, ud means up down)
#define lr A0
#define ud A1

// Degine Servos (lrs means left right servo, uds means up down servo)
Servo lrs;
Servo uds;

void setup() {

//  Begin the Serial (For debugging)
  Serial.begin(9600);

// Set the potentiometers as input
  pinMode(lr, INPUT);
  pinMode(ud, INPUT);

// Attach the servo motors to the pin number
  lrs.attach(7);
  uds.attach(8);

}

void loop() {

//  .write() moves the servo from the value of 0 to 180 Degrees, here I mapped the value of the potentiometer 0 to 180 degrees.
// Range is 5 to 180 because to avoid the servo-correcting itself sound.
  lrs.write(map(analogRead(lr), 0 , 1024 , 5 , 180));
  uds.write(map(analogRead(ud), 0 , 1024 , 5 , 180));

}
